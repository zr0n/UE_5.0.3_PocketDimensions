// Copyright Epic Games, Inc. All Rights Reserved.

#include "GLTFImporterContext.h"
#include "GLTFMaterialElement.h"
#include "GLTFMaterialExpressions.h"
#include "GLTFTextureFactory.h"

#include "Materials/Material.h"
#include "Misc/Paths.h"
#include "PackageTools.h"

class FGLTFMaterialElementFactory : public GLTF::IMaterialElementFactory
{
public:
	virtual GLTF::FMaterialElement* CreateMaterial(const TCHAR* Name, UObject* ParentPackage, EObjectFlags Flags) override
	{
		const FString PackageName  = UPackageTools::SanitizePackageName(FPaths::Combine(ParentPackage->GetName(), TEXT("Materials"), Name));
		UPackage*     AssetPackage = CreatePackage(*PackageName);
		UMaterial*    Material     = NewObject<UMaterial>(AssetPackage, UMaterial::StaticClass(), *FPaths::GetBaseFilename(PackageName), Flags);

		return new FGLTFMaterialElement(Material);
	}
};

FGLTFImporterContext::FGLTFImporterContext()
    : MaterialFactory(new FGLTFMaterialElementFactory(), new FGLTFTextureFactory(LogMessages))
{
}

bool FGLTFImporterContext::OpenFile(const FString& FilePath)
{
	LogMessages.Empty();

	Reader.ReadFile(FilePath, false, true, Asset);

	auto Found =
	    Reader.GetLogMessages().FindByPredicate([](const GLTF::FLogMessage& Message) { return Message.Get<0>() == GLTF::EMessageSeverity::Error; });
	if (Found)
	{
		return false;
	}
	check(Asset.ValidationCheck() == GLTF::FAsset::Valid);

	// check extensions supported
	static const TArray<GLTF::EExtension> SupportedExtensions = { GLTF::EExtension::KHR_MaterialsPbrSpecularGlossiness,
																  GLTF::EExtension::KHR_MaterialsUnlit,
																  GLTF::EExtension::KHR_LightsPunctual,
																  GLTF::EExtension::KHR_MaterialsClearCoat,
																  GLTF::EExtension::KHR_MaterialsTransmission,
																  GLTF::EExtension::KHR_MaterialsSheen,
																  GLTF::EExtension::KHR_MaterialsVariants,
																  GLTF::EExtension::KHR_MaterialsSpecular,
																  GLTF::EExtension::KHR_MaterialsIOR };

	for (GLTF::EExtension Extension : Asset.ExtensionsUsed)
	{
		if (SupportedExtensions.Find(Extension) == INDEX_NONE)
		{
			LogMessages.Emplace(GLTF::EMessageSeverity::Warning, FString::Printf(TEXT("Extension is not supported: %s"), GLTF::ToString(Extension)));
		}
	}

	Asset.GenerateNames(FPaths::GetBaseFilename(FilePath));

	return true;
}

const TArray<UMaterial*>& FGLTFImporterContext::CreateMaterials(UObject* ParentPackage, EObjectFlags Flags)
{
	const TArray<GLTF::FMaterialElement*>& MaterialElements = MaterialFactory.CreateMaterials(Asset, ParentPackage, Flags);

	Materials.Empty(MaterialElements.Num());
	for (const GLTF::FMaterialElement* BaseElement : MaterialElements)
	{
		const FGLTFMaterialElement* MaterialElement = static_cast<const FGLTFMaterialElement*>(BaseElement);
		Materials.Add(MaterialElement->GetMaterial());
	}
	return Materials;
}

const TArray<GLTF::FLogMessage>& FGLTFImporterContext::GetLogMessages() const
{
	LogMessages.Append(Reader.GetLogMessages());
	LogMessages.Append(StaticMeshFactory.GetLogMessages());
	LogMessages.Append(MaterialFactory.GetLogMessages());
	return LogMessages;
}

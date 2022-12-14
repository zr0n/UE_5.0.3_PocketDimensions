// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/EditableText.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/Font.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/Input/SEditableText.h"
#include "Slate/SlateBrushAsset.h"
#include "Styling/UMGCoreStyle.h"

#define LOCTEXT_NAMESPACE "UMG"

/////////////////////////////////////////////////////
// UEditableText

static FEditableTextStyle* DefaultEditableTextStyle = nullptr;

#if WITH_EDITOR
static FEditableTextStyle* EditorEditableTextStyle = nullptr;
#endif 

UEditableText::UEditableText(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	if (DefaultEditableTextStyle == nullptr)
	{
		DefaultEditableTextStyle = new FEditableTextStyle(FUMGCoreStyle::Get().GetWidgetStyle<FEditableTextStyle>("NormalEditableText"));

		// Unlink UMG default colors.
		DefaultEditableTextStyle->UnlinkColors();
	}

	WidgetStyle = *DefaultEditableTextStyle;

#if WITH_EDITOR 
	if (EditorEditableTextStyle == nullptr)
	{
		EditorEditableTextStyle = new FEditableTextStyle(FCoreStyle::Get().GetWidgetStyle<FEditableTextStyle>("NormalEditableText"));

		// Unlink UMG Editor colors from the editor settings colors.
		EditorEditableTextStyle->UnlinkColors();
	}

	if (IsEditorWidget())
	{
		WidgetStyle = *EditorEditableTextStyle;

		// The CDO isn't an editor widget and thus won't use the editor style, call post edit change to mark difference from CDO
		PostEditChange();
	}
#endif // WITH_EDITOR

	ColorAndOpacity_DEPRECATED = FLinearColor::Black;

	if (!IsRunningDedicatedServer())
	{
		static ConstructorHelpers::FObjectFinder<UFont> RobotoFontObj(*UWidget::GetDefaultFontName());
		Font_DEPRECATED = FSlateFontInfo(RobotoFontObj.Object, 12, FName("Bold"));
	}

	IsReadOnly = false;
	IsPassword = false;
	MinimumDesiredWidth = 0.0f;
	IsCaretMovedWhenGainFocus = true;
	SelectAllTextWhenFocused = false;
	RevertTextOnEscape = false;
	ClearKeyboardFocusOnCommit = true;
	SelectAllTextOnCommit = false;
	AllowContextMenu = true;
	VirtualKeyboardTrigger = EVirtualKeyboardTrigger::OnFocusByPointer;
	VirtualKeyboardDismissAction = EVirtualKeyboardDismissAction::TextChangeOnDismiss;
	Clipping = EWidgetClipping::ClipToBounds;
	OverflowPolicy = ETextOverflowPolicy::Clip;

#if WITH_EDITORONLY_DATA
	AccessibleBehavior = ESlateAccessibleBehavior::Auto;
	bCanChildrenBeAccessible = false;
#endif
}

void UEditableText::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	MyEditableText.Reset();
}

TSharedRef<SWidget> UEditableText::RebuildWidget()
{
	MyEditableText = SNew( SEditableText )
		.Style( &WidgetStyle )
		.MinDesiredWidth( MinimumDesiredWidth )
		.IsCaretMovedWhenGainFocus( IsCaretMovedWhenGainFocus )
		.SelectAllTextWhenFocused( SelectAllTextWhenFocused )
		.RevertTextOnEscape( RevertTextOnEscape )
		.ClearKeyboardFocusOnCommit( ClearKeyboardFocusOnCommit )
		.SelectAllTextOnCommit( SelectAllTextOnCommit )
		.OnTextChanged( BIND_UOBJECT_DELEGATE( FOnTextChanged, HandleOnTextChanged ) )
		.OnTextCommitted( BIND_UOBJECT_DELEGATE( FOnTextCommitted, HandleOnTextCommitted ) )
		.VirtualKeyboardType( EVirtualKeyboardType::AsKeyboardType( KeyboardType.GetValue() ) )
		.VirtualKeyboardOptions(VirtualKeyboardOptions)
		.VirtualKeyboardTrigger(VirtualKeyboardTrigger)
		.VirtualKeyboardDismissAction(VirtualKeyboardDismissAction)
		.Justification(Justification)
		.OverflowPolicy(OverflowPolicy);
	
	return MyEditableText.ToSharedRef();
}

void UEditableText::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	TAttribute<FText> TextBinding = PROPERTY_BINDING(FText, Text);
	TAttribute<FText> HintTextBinding = PROPERTY_BINDING(FText, HintText);

	MyEditableText->SetText(TextBinding);
	MyEditableText->SetHintText(HintTextBinding);
	MyEditableText->SetIsReadOnly(IsReadOnly);
	MyEditableText->SetIsPassword(IsPassword);
	MyEditableText->SetAllowContextMenu(AllowContextMenu);
	MyEditableText->SetVirtualKeyboardDismissAction(VirtualKeyboardDismissAction);
	MyEditableText->SetJustification(Justification);
	MyEditableText->SetOverflowPolicy(OverflowPolicy);

	// TODO UMG Complete making all properties settable on SEditableText

	ShapedTextOptions.SynchronizeShapedTextProperties(*MyEditableText);
}

FText UEditableText::GetText() const
{
	if ( MyEditableText.IsValid() )
	{
		return MyEditableText->GetText();
	}

	return Text;
}

void UEditableText::SetText(FText InText)
{
	Text = InText;
	if ( MyEditableText.IsValid() )
	{
		MyEditableText->SetText(Text);
	}
}

void UEditableText::SetIsPassword(bool InbIsPassword)
{
	IsPassword = InbIsPassword;
	if ( MyEditableText.IsValid() )
	{
		MyEditableText->SetIsPassword(IsPassword);
	}
}

void UEditableText::SetHintText(FText InHintText)
{
	HintText = InHintText;
	if ( MyEditableText.IsValid() )
	{
		MyEditableText->SetHintText(HintText);
	}
}

void UEditableText::SetIsReadOnly(bool InbIsReadyOnly)
{
	IsReadOnly = InbIsReadyOnly;
	if ( MyEditableText.IsValid() )
	{
		MyEditableText->SetIsReadOnly(IsReadOnly);
	}
}

void UEditableText::SetJustification(ETextJustify::Type InJustification)
{
	Justification = InJustification;
	if (MyEditableText.IsValid())
	{
		MyEditableText->SetJustification(InJustification);
	}
}

void UEditableText::SetTextOverflowPolicy(ETextOverflowPolicy InOverflowPolicy)
{
	OverflowPolicy = InOverflowPolicy;
	if (MyEditableText.IsValid())
	{
		MyEditableText->SetOverflowPolicy(InOverflowPolicy);
	}
}

void UEditableText::SetClearKeyboardFocusOnCommit(bool bInClearKeyboardFocusOnCommit)
{
	ClearKeyboardFocusOnCommit = bInClearKeyboardFocusOnCommit;
	MyEditableText->SetClearKeyboardFocusOnCommit(ClearKeyboardFocusOnCommit);
}

void UEditableText::SetKeyboardType(EVirtualKeyboardType::Type Type)
{
	KeyboardType = Type;
}

void UEditableText::HandleOnTextChanged(const FText& InText)
{
	OnTextChanged.Broadcast(InText);
}

void UEditableText::HandleOnTextCommitted(const FText& InText, ETextCommit::Type CommitMethod)
{
	OnTextCommitted.Broadcast(InText, CommitMethod);
}

void UEditableText::PostLoad()
{
	Super::PostLoad();

	if ( GetLinkerUEVersion() < VER_UE4_DEPRECATE_UMG_STYLE_ASSETS )
	{
		if ( Style_DEPRECATED != nullptr )
		{
			const FEditableTextStyle* StylePtr = Style_DEPRECATED->GetStyle<FEditableTextStyle>();
			if ( StylePtr != nullptr )
			{
				WidgetStyle = *StylePtr;
			}

			Style_DEPRECATED = nullptr;
		}

		if ( BackgroundImageSelected_DEPRECATED != nullptr )
		{
			WidgetStyle.BackgroundImageSelected = BackgroundImageSelected_DEPRECATED->Brush;
			BackgroundImageSelected_DEPRECATED = nullptr;
		}

		if ( BackgroundImageComposing_DEPRECATED != nullptr )
		{
			WidgetStyle.BackgroundImageComposing = BackgroundImageComposing_DEPRECATED->Brush;
			BackgroundImageComposing_DEPRECATED = nullptr;
		}

		if ( CaretImage_DEPRECATED != nullptr )
		{
			WidgetStyle.CaretImage = CaretImage_DEPRECATED->Brush;
			CaretImage_DEPRECATED = nullptr;
		}
	}

	if (GetLinkerUEVersion() < VER_UE4_DEPRECATE_UMG_STYLE_OVERRIDES)
	{
		if (Font_DEPRECATED.HasValidFont())
		{
			WidgetStyle.Font = Font_DEPRECATED;
			Font_DEPRECATED = FSlateFontInfo();
		}

		if (ColorAndOpacity_DEPRECATED != FLinearColor::Black)
		{
			WidgetStyle.ColorAndOpacity = ColorAndOpacity_DEPRECATED;
			ColorAndOpacity_DEPRECATED = FLinearColor::Black;
		}
	}
}

#if WITH_ACCESSIBILITY
TSharedPtr<SWidget> UEditableText::GetAccessibleWidget() const
{
	return MyEditableText;
}
#endif

#if WITH_EDITOR

const FText UEditableText::GetPaletteCategory()
{
	return LOCTEXT("Input", "Input");
}

#endif

/////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE

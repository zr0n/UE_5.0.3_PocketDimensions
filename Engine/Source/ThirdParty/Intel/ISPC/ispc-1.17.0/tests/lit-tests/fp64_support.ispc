// RUN: %{ispc} %s --target=gen9-x16 --device=skl -h %t.h --emit-llvm-text -o %t.ll
// RUN: FileCheck --input-file=%t.ll -check-prefix=CHECK_FP64_SUPPORTED %s
// RUN: %{ispc} %s --target=xelp-x16 --device=tgllp -h %t.h --emit-llvm-text -o %t.ll
// RUN: FileCheck --input-file=%t.ll -check-prefix=CHECK_FP64_NOT_SUPPORTED %s
// REQUIRES: XE_ENABLED
// CHECK_FP64_SUPPORTED: call void @llvm.genx.svm.block.st.i64.v16f64
#ifdef ISPC_FP64_SUPPORTED
export void test(uniform double out[], uniform double a) {
#else
// CHECK_FP64_NOT_SUPPORTED: call void @llvm.genx.svm.block.st.i64.v16f32
export void test(uniform float out[], uniform float a) {
#endif
  out[programIndex] = a;
}


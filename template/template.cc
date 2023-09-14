#define HWY_DISABLED_TARGETS HWY_PPC10
// Generates code for every target that this compiler can support.
#undef HWY_TARGET_INCLUDE
#define HWY_TARGET_INCLUDE "example.cpp"  // this file
#include <hwy/foreach_target.h>  // must come before highway.h

#include <hwy/highway.h>
#include <hwy/tests/test_util-inl.h>

HWY_BEFORE_NAMESPACE();  // required if not using HWY_ATTR
namespace hwy {
namespace HWY_NAMESPACE {  // required: unique per target

// Calls function defined in skeleton.cc.
struct TestFloorLog2 {
  template <class T, class DF>
  HWY_NOINLINE void operator()(T /*unused*/, DF df) {
    hwy::PreventElision(df);
  }
};

HWY_NOINLINE void TestAllFloorLog2() {
  ForPartialVectors<TestFloorLog2>()(float());
}

}  // namespace HWY_NAMESPACE
}  // namespace project
HWY_AFTER_NAMESPACE();

// The table of pointers to the various implementations in HWY_NAMESPACE must
// be compiled only once (foreach_target #includes this file multiple times).
// HWY_ONCE is true for only one of these 'compilation passes'.
#if HWY_ONCE

namespace hwy {

// This macro declares a static array used for dynamic dispatch.
HWY_EXPORT(TestAllFloorLog2);

int main(int argc, char**) {
  HWY_DYNAMIC_DISPATCH(TestAllFloorLog2)();
  return 0;
}

}  // namespace project
#endif  // HWY_ONCE


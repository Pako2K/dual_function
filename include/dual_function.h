#ifndef DUAL_FUNCTION
#define DUAL_FUNCTION

#include <functional>

namespace utils
{
  template< class>
  class DualFunction;

  template <class RET_TYPE, class... FN_ARGS>
  class DualFunction<RET_TYPE(FN_ARGS...)> {
  protected:
    std::function<RET_TYPE(FN_ARGS...)>   _primaryFn;
    std::function<RET_TYPE(FN_ARGS...)>   _secondaryFn;
    std::function<RET_TYPE(FN_ARGS...)>*  _function{ &_primaryFn };

  public:
    DualFunction(const std::function<RET_TYPE(FN_ARGS...)>& pfn, const std::function<RET_TYPE(FN_ARGS...)>& sfn) : _primaryFn{ pfn }, _secondaryFn{ sfn } {}
        
    inline RET_TYPE operator()(FN_ARGS...args) const { return (*_function)(std::forward<FN_ARGS>(args)...); }

    inline void enableFirst() { _function = &_primaryFn; }
    inline void enableSecond() { _function = &_secondaryFn; }

    inline void switchFn() { this->isFirstFn() ? _function = &_secondaryFn : _function = &_primaryFn; }

    inline bool isFirstFn() const { return _function == &_primaryFn; }
  };
}

#endif DUAL_FUNCTION

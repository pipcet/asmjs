/* http://www.cppsamples.com/common-tasks/apply-tuple-to-function.html */
// http://en.cppreference.com/w/cpp/experimental/apply
#include <string>
#include <tuple>
#include <stdio.h>
#include <cstddef>
#include <tuple>
#include <type_traits>
#include <utility>

template<typename F, typename Tuple, size_t ...S >
decltype(auto) apply_tuple_impl(F&& fn, Tuple&& t, std::index_sequence<S...>)
{
  return std::forward<F>(fn)(std::get<S>(std::forward<Tuple>(t))...);
}

template<typename F, typename Tuple>
decltype(auto) apply_from_tuple(F&& fn, Tuple&& t)
{
  std::size_t constexpr tSize = std::tuple_size<typename std::remove_reference<Tuple>::type>::value;
  return apply_tuple_impl(std::forward<F>(fn), std::forward<Tuple>(t),
                          std::make_index_sequence<tSize>());
}

template<typename T>
class JSV {
public:
  typedef T base_type;
  JSV(T x, T* ptr = nullptr)
  {
  }
};

template<typename T, const char *const str>
class JSX {
public:
  operator T()
  {
    T x;
    const std::string str2 = std::string("%O0 = ") + std::string(str);
    if (!__builtin_constant_p(str2))
      __builtin_unreachable();
    return x;
  }
};

template<int (*f)(...)>
class lift {
  std::string
  operator()(...)
  {
    return "XXX";
  }
};

#define always_inline extern inline __attribute__((always_inline))

template<typename tuple_type>
always_inline void
jsv_initialize(tuple_type &t)
{
}

constexpr const char * const str = "a";

template<typename tuple_type, const size_t i, size_t... is>
always_inline void
jsv_initialize(tuple_type &t)
{
  typename std::remove_reference<decltype(std::get<i>(t))>::type v;
  asm("%O0 = values[%O1];" : "=m" (v) : "i" (i));
  std::get<i>(t) = v;

  jsv_initialize<tuple_type, is...>(t);
}

template<typename tuple_type, const std::size_t... I>
void
jsv_initialize2(tuple_type &t,
                std::index_sequence<I...>)
{
  jsv_initialize<tuple_type, I...>(t);
}

template<typename F, typename... ArgTypes>
std::string
call(F&& f, ArgTypes... args)
{
  constexpr size_t n = sizeof...(args);
  std::tuple<typename ArgTypes::base_type...> t;
  void *ptrs[sizeof...(args) + 1];

  jsv_initialize2(t, std::make_index_sequence<n>());

  //apply_from_tuple(f, t);
}

template<typename T, typename... ArgTypes>
std::string
prepare(void **array, T x, ArgTypes... args)
{
}

int main()
{
  call(printf, JSV<const char *>("%s"), JSV<const char *>("hello world"));
}

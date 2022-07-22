
#include <iostream>
#include <vector>
#include <type_traits>
#include <algorithm>

namespace Debug {

namespace Internal {

template<class T> struct remove_cvref {
  using type = typename std::remove_cv_t<std::remove_reference_t<T>>;
};

template<class T> using remove_cvref_t = typename remove_cvref<T>::type;


template<class T> struct literal_operator { static constexpr const char* value = ""; };
template<> struct literal_operator<unsigned> { static constexpr const char* value = "U"; };
template<> struct literal_operator<long> { static constexpr const char* value = "L"; };
template<> struct literal_operator<long double> { static constexpr const char* value = "L"; };
template<> struct literal_operator<unsigned long> { static constexpr const char* value = "UL"; };
template<> struct literal_operator<long long> { static constexpr const char* value = "LL"; };
template<> struct literal_operator<unsigned long long> { static constexpr const char* value = "ULL"; };

template<class T> inline constexpr auto literal_operator_v = literal_operator<T>::value;


template<template <class...> class Template, class Type> struct is_template : std::false_type {};
template<template <class...> class Template, class... Args> struct is_template<Template, Template<Args...>> : std::true_type {};


template<class T> struct is_loggable {
    template <class U>
    static constexpr auto External(U &&v) -> decltype(_debug(v), std::true_type());
    static constexpr std::false_type External(...);

    template <class U>
    static constexpr auto Member(U &&v) -> decltype(v._debug(), std::true_type());
    static constexpr std::false_type Member(...);

    static constexpr bool value = (
      decltype(External(std::declval<T>()))::value ||
      decltype(Member(std::declval<T>()))::value
    );

};

template<class T> inline constexpr auto is_loggable_v = is_loggable<T>::value;


template<class T> struct has_iterator {
    template <class U>
    static constexpr auto ADL(U &&v) -> decltype(begin(v), end(v), std::true_type());
    static constexpr std::false_type ADL(...);

    template <class U>
    static constexpr auto STD(U &&v) -> decltype(std::begin(v), std::end(v), std::true_type());
    static constexpr std::false_type STD(...);

    template <class U>
    static constexpr auto Member(U &&v) -> decltype(v.begin(), v.end(), std::true_type());
    static constexpr std::false_type Member(...);
};


template<class T> struct is_iterable : has_iterator<T> {
    static constexpr bool value = (
      decltype(has_iterator<T>::ADL(std::declval<T>()))::value ||
      decltype(has_iterator<T>::STD(std::declval<T>()))::value ||
      decltype(has_iterator<T>::Member(std::declval<T>()))::value
    );
};

template<class T> inline constexpr auto is_iterable_v = is_iterable<T>::value;


template<class T> struct iterator_resolver : has_iterator<T> {
  template<typename U>
  static auto begin(U&& v){
    using U_t = remove_cvref_t<U>;

    static_assert(std::is_same_v<U_t, remove_cvref_t<T>>);
    static_assert(is_iterable_v<T>);

    if constexpr (decltype(has_iterator<T>::Member(std::declval<U_t>()))::value){
      return v.begin();
    } else {
      using std::begin;
      return begin(std::forward<U>(v));
    }
  }

  template<typename U>
  static auto end(U&& v){
    using U_t = remove_cvref_t<U>;

    static_assert(std::is_same_v<U_t, remove_cvref_t<T>>);
    static_assert(is_iterable_v<T>);

    if constexpr (decltype(has_iterator<T>::Member(std::declval<U_t>()))::value){
      return v.end();
    } else {
      using std::end;
      return end(std::forward<U>(v));
    }
  }
};

}  // namespace internal

}  // namespace atcoder

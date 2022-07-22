#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <utility>

#include <atcoder/modint>

#include "./internal_type_traits.hpp"

namespace Debug {

using namespace std;

#define cdebug clog

const string COLOR_INIT = "\033[m";
const string COLOR_STRING = "\033[33m";
const string COLOR_TYPE = "\033[34m";
const string COLOR_NUMERIC = "\033[36m";
const string COLOR_LITERAL_OPERATOR = "\033[31m";

template <class T> int depth(T) { return 0; }
template <class T> int depth(vector<T>) { return depth(T ()) + 1; }

using Brackets = pair<string, string>;

template <class T, enable_if_t<Internal::is_iterable_v<T> && !Internal::is_template<map,T>::value>* = nullptr>
string lit(T, Brackets = { "[", "]" }, string = ", ");

template <class T, enable_if_t<Internal::is_template<map,T>::value>* = nullptr>
string lit(T, Brackets = { "[", "]" }, string = ", ");

template <class I> string lit(I, I, Brackets = { "[", "]" }, string = ", ");

template<class F, class S> string lit(pair<F, S>);
template<class... T> string lit(tuple<T...>);

template <size_t N = 0, class T> void iterate_tuple(T, stringstream&);

struct debug_t : string {
    using string::string;
    debug_t(const string &str) {
        this->assign(str);
    }
};
string lit(debug_t info) {
    return info;
}

string lit(nullptr_t) {
    return COLOR_INIT;
}
string lit(string &val) {
    stringstream res;
    res << COLOR_STRING << "`" << val << "`" << COLOR_INIT;
    return res.str();
}
string lit(const char &val) {
    stringstream res;
    res << COLOR_STRING << "\'", res << val, res << "\'" << COLOR_INIT;
    return res.str();
}
string lit(const char val[]) {
    stringstream res;
    res << COLOR_STRING << "\"", res << val, res << "\"" <<  COLOR_INIT;
    return res.str();
}

template <class T, enable_if_t<is_arithmetic_v<T>>* = nullptr> string lit(T val) {
    stringstream res;
    res << COLOR_NUMERIC << fixed << setprecision(numeric_limits<T>::max_digits10) << scientific;
    res << val << COLOR_LITERAL_OPERATOR << Internal::literal_operator_v<T>;
    res << COLOR_INIT;
    return res.str();
};

template<class T, atcoder::internal::is_modint_t<T> * = nullptr> string lit(T val) {
    return COLOR_TYPE + "<modint> " + lit(val.val());
}
template <class K, class V> string lit(map<K, V> mp) {
    return lit(mp, Brackets(COLOR_TYPE + "<map>" + COLOR_INIT + " {", "}"));
}
template <class K, class V> string lit(unordered_map<K, V> mp) {
    return lit(mp, Brackets(COLOR_TYPE + "<unordered_map>" + COLOR_INIT + " {", "}"));
}
template <class T> string lit(set<T> st) {
    return lit(st, Brackets(COLOR_TYPE + "<set>" + COLOR_INIT + " {", "}"));
}
template <class T> string lit(unordered_set<T> st) {
    return lit(st, Brackets(COLOR_TYPE + "<unordered_set>" + COLOR_INIT + " {", "}"));
}
template <class T> string lit(vector<T> vec) {
    return lit(vec, Brackets(COLOR_TYPE + "<vector>" + COLOR_INIT + " [", "]"));
}
template <class T> string lit(deque<T> deq) {
    return lit(deq, Brackets(COLOR_TYPE + "<deque>" + COLOR_INIT + " [", "]"));
}

template<class F, class S> string lit(pair<F, S> pr) {
    stringstream res;
    res << COLOR_TYPE << "<pair>" << COLOR_INIT << " ( ";
    res << lit(pr.first);
    res << ", ";
    res << lit(pr.second);
    res << " )";
    return res.str();
}
template<class... T> string lit(tuple<T...> tpl) {
    stringstream res;
    res << COLOR_TYPE << "<tuple>" << COLOR_INIT << " ( ";
    iterate_tuple(tpl, res);
    res << " )";
    return res.str();
}

template <size_t N = 0, class T> void iterate_tuple(T val, stringstream &res) {
    if constexpr(N < tuple_size_v<T>) {
        res << lit(get<N>(val));
        if constexpr(N < tuple_size_v<T> - 1) res << ", ";
        iterate_tuple<N + 1>(val, res);
    }
}

template <class I> string lit(I first, I last, Brackets brcs, string spl) {
    stringstream res;
    res << brcs.first << " ";
    while(first != last) {
        if(distance(first, last)<=1) res << lit(*first) << " ";
        else res << lit(*first) << spl;
        ++first;
    }
    res << brcs.second ;
    return res.str();
}

template <class T, enable_if_t<Internal::is_iterable_v<T> && !Internal::is_template<map,T>::value>* = nullptr>
string lit(T val, Brackets brcs, string sep) {
    return lit(Internal::iterator_resolver<T>::begin(val), Internal::iterator_resolver<T>::end(val), brcs, sep);
}

template <class T, enable_if_t<Internal::is_template<map,T>::value>* = nullptr>
string lit(T val, Brackets brcs, string sep) {
    return lit(val.begin(), val.end(), brcs, sep);
}

template<class T> string lit(T *val) {
    return lit(*val);
}

template<class T, enable_if_t<Internal::is_loggable_v<T>>* = nullptr>
string lit(T val) {
    auto res = val._debug();
    clog <<  typeid(res).name() << endl;
    if constexpr(is_same_v<decltype(res),debug_t>) {
        clog << "denig_t" << endl;
        return res;
    } else {
        clog << "non denig_t" << endl;
        return lit(res);
    }
}

template <class T = nullptr_t> void debug(T = nullptr, string = "\n");

template<class T> void debug(T val, string endl) {
    cdebug << lit(val) << endl;
}


vector<string> split(string str) {
    str += ',';
    vector<string> res;
    while(!str.empty()) {
        res.push_back(str.substr(0, str.find(',')));
        str = str.substr(str.find(',') + 1);
    }
    return res;
}

template<class Arg> void DEBUG(nullptr_t, Arg arg) { cdebug << arg; }
template<class ...Args> void DEBUG(Args... args) { cdebug << lit(args...); }

void debug(
    vector<string> __attribute__ ((unused)) args,
    __attribute__ ((unused)) size_t idx,
    __attribute__ ((unused)) int LINE_NUM
) { debug(nullptr, COLOR_INIT + "\n"); }

template <typename Head, typename... Tail> void debug(vector<string> args, size_t idx, int LINE_NUM, Head H, Tail... T) {
    if(idx > 0) debug(nullptr, ","); else debug(nullptr, "\033[3;35m#" + to_string(LINE_NUM) + "  " + COLOR_INIT);
    debug(nullptr, "\033[32m" + args[idx]  + COLOR_INIT + ": ");
    debug(H, string());
    debug(args, idx + 1, 0, T...);
}

} // namespace debug

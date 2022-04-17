#include <iostream>
#include <thread>
#include <chrono>
#include <functional>

// Needs to be compiled with -std=c++1y for optionals support

#include <chrono>
#include <cstdio>
#include <cstring>
#include <optional>
#include <future>
#include <type_traits>

// A shortcut to the result type of F(Args...).
template <typename F, typename... Args>
using result_t = typename std::result_of<
    typename std::decay<F>::type(typename std::decay<Args>::type...)>::type;

// A shortcut to the type of a duration D.
template <typename D>
using duration_t = std::chrono::duration<
    typename D::rep, typename D::period>;

// Run a function asynchronously if timeout is non-zero.
//
// The return value is an optional<result_t>.
// The optional is "empty" if the async execution timed out.
template <typename TO, typename F, typename... Args>
std::optional<result_t<F, Args...>>
with_timeout(const TO &timeout, F &&f, Args &&...args)
{
    if (timeout == duration_t<TO>::zero())
        return std::make_optional(f(args...));

    std::printf("launching...\n");
    auto future = std::async(std::launch::async,
                             std::forward<F>(f), std::forward<Args...>(args...));
    auto status = future.wait_for(timeout);
    std::printf("wait_for() is back\n");
    if (status == std::future_status::ready)
        return std::make_optional(future.get());
    return std::optional<result_t<F, Args...>>();
}

std::optional<result_t<std::function<int(int)>, int>> is_executed(std::chrono::milliseconds timeout, std::function<int(int)> f, int arg)
{

    std::printf("launching...\n");
    auto future = std::async(std::launch::async,
                             std::forward<std::function<int(int)>>(f), std::forward<int>(arg));
    auto status = future.wait_for(timeout);
    std::printf("wait_for() is back\n");
    if (status == std::future_status::ready)
        return std::make_optional(future.get());
    return std::optional<result_t<std::function<int(int)>, int>>();
}

using namespace std::chrono_literals;

int main()
{
    int i = 9;

    auto increment = [](int i)
    {
        while (true)
            i++;
        return i;
    };

    std::future<int> future = std::async(std::launch::async, increment, i);

    //     // auto f = with_timeout(std::chrono::milliseconds(1), std::strlen, "12");
    //     auto f = is_executed(std::chrono::milliseconds(10), increment, i);
    //     if (f)
    //         std::printf("result = %zu\n", *f);
    //     else
    //         std::printf("timeout!\n");
    // }
    auto status = future.wait_for(1s);
    if (status == std::future_status::timeout)
        std::cout << "timeout\n";
    if (status == std::future_status::ready)
        std::cout << "ready!\n";
}
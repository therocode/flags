# flags
A way to define flag types as a typesafe alternative to enums that includes flag operations and no arithmetic operations

## Usage

```cpp
//here we define a new flags type
//it has a tag to make it typesafely unique
//it contains the flag constants
//the nested ::type is used to denote the type in usage
namespace window_flags
{
    struct window_flags_tag{};
    using type = flag<int, window_flags_tag>::type;

    constexpr type None            = type::none_flag();
    constexpr type NoBorder        = type::from_index(0);
    constexpr type AllowFullscreen = type::from_index(1);
    constexpr type AllowResize     = type::from_index(2);
};

//then we can do
struct Window
{
    window_flags::type flags;
};

bool can_resize_and_fullscreen(Window& w)
{
    return w.flags & window_flags::AllowResize &&
           w.flags & window_flags::AllowFullscreen;
}
```

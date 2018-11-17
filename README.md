# flags
A way to define flag types as a typesafe alternative to enums that includes flag operations and no arithmetic operations

## Usage

```cpp
//here we define a new flags type
//it has a tag to make it typesafely unique
//it contains the flag constants
struct window_flags : flg::flags<int, window_flags>
{
    constexpr static type None            = none_flag();
    constexpr static type NoBorder        = from_index(0);
    constexpr static type AllowFullscreen = from_index(1);
    constexpr static type AllowResize     = from_index(2);
};

//then we can do
struct Window
{
    window_flags flags;
};

bool can_resize_and_fullscreen(Window& w)
{
    return w.flags & window_flags::AllowResize &&
           w.flags & window_flags::AllowFullscreen;
}
```

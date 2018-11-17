# flags
A way to define flag types as a typesafe alternative to enums that includes flag operations and no arithmetic operations

## Features
 * Typesafe: No implicit conversions to underlying type, and cannot interact with other flag types
 * Has bitwise operators defined to do flag operations
 * Explicitly castable to underlying type
 * Clear and simple usage

## Usage

```cpp
//example of how a new flags type is defined
//
//the first parameter is the underlying data type
//the second parameter is the new type itself
struct window_flags : flg::flags<int, window_flags>
{
    constexpr static type None            = none_flag();  //all bits set to 0
    constexpr static type NoBorder        = from_index(0); //first bit set to 1
    constexpr static type AllowFullscreen = from_index(1); //second bit set to 1
    constexpr static type AllowResize     = from_index(2); //third bit set to 1
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

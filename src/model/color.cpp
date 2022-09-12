#include <shapes2d/color.hpp>


const shapes2d::Color shapes2d::Color::white = 0xFFFFFFFF;
const shapes2d::Color shapes2d::Color::black = 0x00000000;


shapes2d::Color shapes2d::Palette::operator[](int index) const
{
    const auto N = colors.size();
    if (N == 0) {
        return Color::white;
    }

    if (index < 0) {
        return colors[0];
    }
    return colors[index % N];
}


shapes2d::Palette shapes2d::Palette::defaultPalette()
{
    return paletteWarm();
}


shapes2d::Palette shapes2d::Palette::paletteWarm()
{
    shapes2d::Palette res;
    res.colors.push_back(0x845EC2);
    res.colors.push_back(0xD65DB1);
    res.colors.push_back(0xFF6F91);
    res.colors.push_back(0xFF9671);
    res.colors.push_back(0xFFC75F);
    res.colors.push_back(0xF9F871);
    return res;
}


shapes2d::Color::Color(ARGBEncoded argb)
    : argb(argb)
{
}


shapes2d::Color::operator uint32_t() const
{
    return argb;
}

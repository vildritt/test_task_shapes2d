#ifndef SHAPES2D_COLOR_H
#define SHAPES2D_COLOR_H
#pragma once

#include <cstdint>
#include <vector>


namespace shapes2d {

using Color = int32_t; // TODO 1: improve - make class?

struct Colors {
    static const Color white;
    static const Color black;
};


struct Palette {
    std::vector<Color> colors;

    Color operator[](int index) const;

    static Palette defaultPalette();
    static Palette paletteWarm();
};


} // ns shapes2d


#endif // SHAPES2D_COLOR_H



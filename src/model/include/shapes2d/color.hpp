#ifndef SHAPES2D_COLOR_H
#define SHAPES2D_COLOR_H
#pragma once

#include <cstdint>
#include <vector>
#include <shapes2d/export.h>


namespace shapes2d {

// Encoded 0x00RRGGBB
using Color = int32_t; // TODO 1: improve - make class?

struct SHAPES2D_MODEL_EXPORT Colors {
    static const Color white;
    static const Color black;
};


struct SHAPES2D_MODEL_EXPORT Palette {
    std::vector<Color> colors;

    Color operator[](int index) const;

    static Palette defaultPalette();
    static Palette paletteWarm();
};


} // ns shapes2d


#endif // SHAPES2D_COLOR_H



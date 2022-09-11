#ifndef SHAPES2D_COLOR_H
#define SHAPES2D_COLOR_H
#pragma once

#include <cstdint>
#include <vector>
#include <shapes2d/export.h>


namespace shapes2d {


/**
 * @brief Color RGB encoded
 */
struct SHAPES2D_MODEL_EXPORT Color {
    // Encoded ARGB: 0xAARRGGBB
    using ARGBEncoded = uint32_t;

    ARGBEncoded argb;

    Color(ARGBEncoded argb = Color::black);
    operator uint32_t() const;

    // simple colors constants

    static const Color white;
    static const Color black;
};


/**
 * @brief Simply set of colors, nicely looks with each other
 */
struct SHAPES2D_MODEL_EXPORT Palette {
    std::vector<Color> colors;

    /**
     * @brief get paletter color by index. Indexes are cycled (mod size op)
     */
    Color operator[](int index) const;

    /**
     * @brief use when have no preferences
     */
    static Palette defaultPalette();

    /**
     * @brief one generated with warm colors
     */
    static Palette paletteWarm();
};


} // ns shapes2d


#endif // SHAPES2D_COLOR_H



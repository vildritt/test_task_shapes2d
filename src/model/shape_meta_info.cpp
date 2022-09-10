#include <shapes2d/shape_meta_info.hpp>


shapes2d::ShapePtr shapes2d::shape::Factory::create()
{
    return doCreate();
}

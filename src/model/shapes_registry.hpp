#ifndef SHAPES2D_SHAPES_REGISTRY_H_PRIVATE
#define SHAPES2D_SHAPES_REGISTRY_H_PRIVATE
#pragma once


#include <shapes2d/shapes_registry.hpp>


namespace shapes2d {
namespace shape {


/// registration helpers


template<typename T>
class DefaultFactory : public Factory {
protected:
    ShapePtr doCreate() override {
        return std::make_shared<T>();
    }
};


template<typename T>
FactoryPtr createDefaultFactory()
{
    return std::make_shared<DefaultFactory<T>>();
}



template<typename T>
struct ShapeRegistratorHelper {
    ShapeRegistratorHelper(const shapes2d::shape::Identifier& id, shapes2d::shape::MetaInfo* meta) {
        meta->id = id;
        meta->factory = shapes2d::shape::createDefaultFactory<T>();
        meta->typeIndex = shapes2d::typeIndex<T>();
        shapes2d::shape::Registry::instance().registerShape(meta);
    }
};


/**
 * Use this two macros for new shapes to register
 * TODO 0: this works only if shared lib used, for static - need to manually register all shapes!
 */
#define S2D_SHAPE_REGITRATOR_HELPER(ClassName, Id)                    \
namespace {                                                           \
                                                                      \
shapes2d::shape::MetaInfo metaInfo;                                   \
                                                                      \
using Helper = shapes2d::shape::ShapeRegistratorHelper<ClassName>;    \
const struct Registrator : public Helper {                            \
    Registrator() : Helper(Id, &metaInfo) {}                          \
} registrator;                                                        \
                                                                      \
} /* ns a*/                                                           \
                                                                      \
const shapes2d::shape::MetaInfo *ClassName::getMeta() const           \
{                                                                     \
    return &::metaInfo;                                               \
}



#define S2D_SHAPE_REGITRATOR_HELPER_DEFAULT(ClassName)  \
    S2D_SHAPE_REGITRATOR_HELPER(ClassName, #ClassName)



} // shape
} // ns shapes2d


#endif // SHAPES2D_SHAPES_REGISTRY_H_PRIVATE

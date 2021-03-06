//
//  render_component.h
//  OpenGLFramework
//
//  Created by Laszlo Korte on 10.08.14.
//  Copyright (c) 2014 Laszlo Korte. All rights reserved.
//

#ifndef __OpenGLFramework__render_component__
#define __OpenGLFramework__render_component__

#include "./base_component.h"
#include "../../graphics/geometry_object.h"
#include "../../graphics/material.h"

namespace lkogl {
    namespace scene {
        namespace components {
            class RenderComponent : public Component {
                graphics::GeometryObject geometry_;
                graphics::Material material_;
            public:
                RenderComponent(graphics::GeometryObject geo, graphics::Material mat);
                ~RenderComponent();

                void update(Entity& transformation) const override;
                void render(const Entity& transformation, const graphics::shader::ProgramUse&) const override;
            };
        }
    }
}

#endif /* defined(__OpenGLFramework__render_component__) */

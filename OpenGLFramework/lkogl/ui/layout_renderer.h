//
//  layout_renderer.h
//  OpenGLFramework
//
//  Created by Laszlo Korte on 15.08.14.
//  Copyright (c) 2014 Laszlo Korte. All rights reserved.
//

#ifndef __OpenGLFramework__layout_renderer__
#define __OpenGLFramework__layout_renderer__

#include "./element.h"
#include "../graphics/shader/program.h"
#include "../graphics/render_target.h"
#include "../graphics/geometry_object.h"

namespace lkogl {
    namespace ui {
        class LayoutRenderer {
            graphics::shader::Program program_;
            graphics::GeometryObject square_;
        public:
            LayoutRenderer();
            ~LayoutRenderer();
            
            void render(std::shared_ptr<Element> e, const graphics::Screen& screen);
        private:
            graphics::shader::Program createProgram() const;
        };
    }
}

#endif /* defined(__OpenGLFramework__layout_renderer__) */

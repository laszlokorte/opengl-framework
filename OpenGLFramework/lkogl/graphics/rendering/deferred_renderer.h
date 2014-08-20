//
//  deferred_renderer.h
//  OpenGLFramework
//
//  Created by Laszlo Korte on 14.08.14.
//  Copyright (c) 2014 Laszlo Korte. All rights reserved.
//

#ifndef __OpenGLFramework__deferred_renderer__
#define __OpenGLFramework__deferred_renderer__

#include "../shader/program.h"
#include "../../scene/node.h"
#include "../render_target.h"
#include "../material.h"
#include "../geometry_object.h"
#include "../../camera/camera.h"

namespace lkogl {
    namespace graphics {
        namespace rendering {
            class DeferredRenderer {
                struct Programs {
                    shader::Program skybox_;
                    shader::Program deferredGeo_;
                    shader::Program deferredAmbient_;
                    shader::Program deferredStencil_;
                    shader::Program deferredDir_;
                } programs_;
                std::unique_ptr<FrameBuffer> buffer_;
                struct {
                    int x, y, width, height;
                } viewport_;
                Screen screen_;
                int ratioWidth_, ratioHeight_;
                GeometryObject square_;
                GeometryObject box_;
                Texture sky_;
            public:
                DeferredRenderer(const Screen& screen, int ratioW, int ratioH);
                ~DeferredRenderer();
                
                void render(std::shared_ptr<scene::Node> graph, const camera::Camera& cam) const;
                
                void resize(int w, int h);
                
            private:
                Programs initPrograms();
            };
        }
    }
}

#endif /* defined(__OpenGLFramework__deferred_renderer__) */

//
//  draggable_behaviour.cpp
//  OpenGLFramework
//
//  Created by Laszlo Korte on 19.08.14.
//  Copyright (c) 2014 Laszlo Korte. All rights reserved.
//

#include "draggable_behaviour.h"
#include "element.h"

#include <iostream>

namespace lkogl {
    namespace ui {
        namespace behaviour {
            DraggableBehaviour::DraggableBehaviour()
            {
            }
            
            DraggableBehaviour::~DraggableBehaviour()
            {
            }
            
            
            void DraggableBehaviour::onInit(Element& el)
            {
                el.style().setBackground(math::Vec4<float>{1,1,1,1});
            }
            
            bool DraggableBehaviour::onFocus(Element& el)
            {
                
                return true;
            }
            
            bool DraggableBehaviour::onBlur(Element& el)
            {
                
                return true;
            }
            
            bool DraggableBehaviour::onContactBegin(Element& el, const math::Vec2<int>& pos)
            {
                el.style().setBackground(el.style().background() + math::Vec4<float>{0,0,0,0.2});
                baseSpacing_ = el.layout().margin();
                basePos_ = pos;
                
                return false;
            }
            
            bool DraggableBehaviour::onContactEnd(Element& el, const math::Vec2<int>& pos)
            {
                el.style().setBackground(el.style().background() - math::Vec4<float>{0,0,0,0.2});
                
                return true;
            }
            
            bool DraggableBehaviour::onContactMove(Element& el, const math::Vec2<int>& pos)
            {
                math::Vec2<int> diff = pos - basePos_;
                el.layout().setMargin((baseSpacing_ + Space{diff.y, 0, 0, diff.x}));
                el.layout().clampMargin();
                
                return true;
            }
            
            
            bool DraggableBehaviour::onContactCancel(Element& el)
            {
                el.style().setBackground(el.style().background() - math::Vec4<float>{0,0,0,0.2});
                
                return true;
            }
            
        }
    }
}
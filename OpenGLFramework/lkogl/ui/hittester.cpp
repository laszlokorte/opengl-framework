//
//  hittester.cpp
//  OpenGLFramework
//
//  Created by Laszlo Korte on 16.08.14.
//  Copyright (c) 2014 Laszlo Korte. All rights reserved.
//

#include "./hittester.h"
#include <queue>

namespace lkogl {
    namespace ui {

        HitTester::HitTester()
        {
        }
        
        HitTester::~HitTester()
        {
        }
        
        std::vector<std::shared_ptr<Element>> HitTester::test(std::shared_ptr<Element> el, math::Vec2<int> hit) const
        {
            std::queue<std::shared_ptr<Element>> elements;
            std::vector<std::shared_ptr<Element>> effectedElements;
            
            elements.push(el);
            
            while(!elements.empty()) {
                std::shared_ptr<Element> current = elements.front();
                elements.pop();
                
                if(current->layout().rectangle().contains(hit)) {
                    effectedElements.push_back(current);
                    std::queue<std::shared_ptr<Element>> empty;
                    elements.swap(empty);
                    
                    auto children = current->children();
                    
                    for(auto i=children.crbegin();i!=children.crend();i++) {
                        elements.push(*i);
                    }
                } else if(current->layout().overflow()) {
                    auto children = current->children();
                    
                    for(auto i=children.crbegin();i!=children.crend();i++) {
                        elements.push(*i);
                    }
                }
            }
            
            return effectedElements;
        }
    }
}
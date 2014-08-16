//
//  layout.cpp
//  OpenGLFramework
//
//  Created by Laszlo Korte on 15.08.14.
//  Copyright (c) 2014 Laszlo Korte. All rights reserved.
//

#include "layout.h"

namespace lkogl {
    namespace ui {
        Layout::Layout()
        {
        }
        
        Layout::~Layout()
        {
        }
                
        void Layout::setParent(const Layout* parent)
        {
            parent_ = parent;
            dirty_ = true;
        }
        
        void Layout::setMargin(const Space& space)
        {
            margin_ = space;
            dirty_ = true;
        }
        
        void Layout::setAlignment(const WeightPlanar& weight)
        {
            alignment_ = weight;
            dirty_ = true;
        }
        
        void Layout::setWidth(Length w)
        {
            width_ = w;
            dirty_ = true;
        }
        
        void Layout::setHeight(Length h)
        {
            height_ = h;
            dirty_ = true;
        }
        
        const Rectangle& Layout::rectangle() const
        {
            if(dirty_) {
                Rectangle parentRect;
                if(parent_ != 0) parentRect = parent_->rectangle();
                
                int mT = margin_.top.calc(parentRect.height());
                int mR = margin_.right.calc(parentRect.width());
                int mB = margin_.bottom.calc(parentRect.height());
                int mL = margin_.left.calc(parentRect.width());
                
                rectangle_.setSize(width_.calc(parentRect.width()-mR-mL), height_.calc(parentRect.height()-mT-mB));
                
                math::Vec2<int> parentSize = math::max(parentRect.size(), rectangle_.size());
                
                rectangle_.setCenter(parentRect.topLeft() + calcCenter({rectangle_.width(), rectangle_.height()}, {parentSize.x,parentSize.y}, mT, mR, mB, mL));
                
                dirty_ = false;
            }
            
            return rectangle_;
        }
        
        Rectangle::Position Layout::calcCenter(const Rectangle::Position& selfSize, const Rectangle::Position& parentSize, int mT, int mR, int mB, int mL) const {
            return {
                (alignment_.left_ * mL
                 + alignment_.right_ * (parentSize.x - (selfSize.x + mR)))
                / (alignment_.left_+alignment_.right_)
                + selfSize.x/2,
                
                (alignment_.top_ * mT
                 + alignment_.bottom_ * (parentSize.y - (selfSize.y + mB)))
                / (alignment_.top_+alignment_.bottom_)
                + selfSize.y/2
            };
        }
    }
}
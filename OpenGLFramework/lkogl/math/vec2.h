//
//  vec2.h
//  OpenGLFramework
//
//  Created by Laszlo Korte on 08.08.14.
//  Copyright (c) 2014 Laszlo Korte. All rights reserved.
//

#ifndef __OpenGLFramework__vec2__
#define __OpenGLFramework__vec2__

#include "./base.h"

namespace lkogl {
    namespace math {
        typedef float basetype;
        
        template <typename T = basetype>
        struct Vec2 {
            T x, y;
            
            Vec2() : x(0), y(0)
            {
            }
            
            Vec2(const Vec2<T>& o) : x(o.x), y(o.y)
            {
            }
            
            Vec2(const T& xp, const T& yp) : x(xp), y(yp)
            {
            }
            
            explicit Vec2(const T& v) : x(v), y(v)
            {
            }
            
            ~Vec2()
            {
            }
            
            
            T & operator[](int i)
            {
                return (&x)[i];
            }
            
            T const & operator[](int i) const
            {
                return (&x)[i];
            }
            
            
            Vec2<T> & operator= (Vec2<T> const & other)
            {
                x = other.x;
                y = other.y;
                
                return *this;
            }
            
            
            Vec2<T> & operator+= (T s)
            {
                x += s;
                y += s;
                
                return *this;
            }
            
            
            Vec2<T> & operator+= (Vec2<T> const & m)
            {
                x += m.x;
                y += m.y;
                
                return *this;
            }
            
            
            Vec2<T> & operator-= (T s)
            {
                x -= s;
                y -= s;
                
                return *this;
            }
            
            
            Vec2<T> & operator-= (Vec2<T> const & m)
            {
                x -= m.x;
                y -= m.y;
                
                return *this;
            }
            
            
            Vec2<T> & operator*= (T s)
            {
                x *= s;
                y *= s;
                
                return *this;
            }
            
            
            Vec2<T> & operator*= (Vec2<T> const & m)
            {
                x *= m.x;
                y *= m.y;
                
                return *this;
            }
            
            
            Vec2<T> & operator/= (T s)
            {
                x /= s;
                y /= s;
                
                return *this;
            }
            
            
            Vec2<T> & operator/= (Vec2<T> const & m)
            {
                x /= m.x;
                y /= m.y;
                
                return *this;
            }
            
            
            Vec2<T> & operator++ ()
            {
                ++x;
                ++y;
                
                return *this;
            }
            
            Vec2<T> & operator-- ()
            {
                --x;
                --y;
                
                return *this;
            }
            
            Vec2<T> operator++(int)
            {
                Vec2<T> result(*this);
                ++*this;
                
                return result;
            }
            
            Vec2<T> operator--(int)
            {
                Vec2<T> result(*this);
                --*this;
                
                return result;
            }
            
            
        };
        
        
        ////////////////////
        /// Binary operators
        ////////////////////
        
        // operator+
        template <typename T>
        Vec2<T> operator+ (const Vec2<T>& a, const Vec2<T>& b)
        {
            return (Vec2<T>(a) += b);
        }
        
        
        template <typename T>
        Vec2<T> operator+ (const Vec2<T>& a, const T& b)
        {
            return (Vec2<T>(a) += b);
        }
        
        
        template <typename T>
        Vec2<T> operator+ (const T& a, const Vec2<T>& b)
        {
            return (Vec2<T>(b) += a);
        }
        
        
        
        // operator-
        template <typename T>
        Vec2<T> operator- (const Vec2<T>& a, const Vec2<T>& b)
        {
            return (Vec2<T>(a) -= b);
        }
        
        
        template <typename T>
        Vec2<T> operator- (const Vec2<T>& a, const T& b)
        {
            return (Vec2<T>(a) -= b);
        }
        
        
        template <typename T>
        Vec2<T> operator- (const T& a, const Vec2<T>& b)
        {
            return Vec2<T>(a-b.x, a-b.y);
        }
        
        
        
        // operator*
        template <typename T>
        Vec2<T> operator* (const Vec2<T>& a, const Vec2<T>& b)
        {
            return (Vec2<T>(a) *= b);
        }
        
        
        template <typename T>
        Vec2<T> operator* (const Vec2<T>& a, const T& b)
        {
            return (Vec2<T>(a) *= b);
        }
        
        
        template <typename T>
        Vec2<T> operator* (const T& a, const Vec2<T>& b)
        {
            return (Vec2<T>(b) *= a);
        }
        
        
        
        // operator/
        template <typename T>
        Vec2<T> operator/ (const Vec2<T>& a, const Vec2<T>& b)
        {
            return (Vec2<T>(a) /= b);
        }
        
        
        template <typename T>
        Vec2<T> operator/ (const Vec2<T>& a, const T& b)
        {
            return (Vec2<T>(a) /= b);
        }
        
        
        template <typename T>
        Vec2<T> operator/ (const T& a, const Vec2<T>& b)
        {
            return Vec2<T>(a/b.x, a/b.y);
        }
        
        
        
        // operator==
        template <typename T>
        bool operator==(Vec2<T> const & v1, Vec2<T> const & v2)
        {
            return (v1.x == v2.x) && (v1.y == v2.y);
        }
        
        
        template <typename T>
        bool operator!=(Vec2<T> const & v1, Vec2<T> const & v2)
        {
            return !(v1==v2);
        }
        
        
        template <typename T>
        bool operator>>(Vec2<T> const & v1, Vec2<T> const & v2)
        {
            return v1.x > v2.x && v1.y > v2.y;
        }
        
        template <typename T>
        bool operator<<(Vec2<T> const & v1, Vec2<T> const & v2)
        {
            return v1.x < v2.x && v1.y < v2.y;
        }
        
        ////////////////////////////
        /// Unary constant operators
        ////////////////////////////
        template <typename T>
        Vec2<T> const operator- (Vec2<T> const & a)
        {
            return Vec2<T>(-a.x, -a.y);
        }
        
        template <typename T>
        T dot(Vec2<T> const & q, Vec2<T> const & p)
        {
            return q.x * p.x + q.y * p.y;
        }
        
        template <typename T>
        T length(const Vec2<T>& v)
        {
            return sqrt(length2(v));
        }
        
        template <typename T>
        T length2(const Vec2<T>& v)
        {
            return dot(v,v);
        }
        
        template <typename T>
        T max(const Vec2<T>& v)
        {
            return v.x>v.y ? v.x:v.y;
        }
        
        template <typename T>
        Vec2<T> max(const Vec2<T>& a, const Vec2<T>& b)
        {
            return {
                math::max(a.x, b.x),
                math::max(a.y, b.y)
            };
        }
        
        template <typename T>
        Vec2<T> min(const Vec2<T>& a, const Vec2<T>& b)
        {
            return {
                math::min(a.x, b.x),
                math::min(a.y, b.y)
            };
        }
        
        template <typename T>
        Vec2<T> normalize(const Vec2<T>& v)
        {
            T len = length(v);
            if(len <= T(0)) {
                return Vec2<T>(0, 0);
            }
            
            T oneOverLen = T(1) / len;
            
            return Vec2<T>(v.x * oneOverLen, v.y * oneOverLen);
        }
        
    }
}

#endif /* defined(__OpenGLFramework__vec2__) */

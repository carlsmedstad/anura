/*
	Copyright (C) 2003-2013 by Kristina Simpson <sweet.kristas@gmail.com>
	
	This software is provided 'as-is', without any express or implied
	warranty. In no event will the authors be held liable for any damages
	arising from the use of this software.

	Permission is granted to anyone to use this software for any purpose,
	including commercial applications, and to alter it and redistribute it
	freely, subject to the following restrictions:

	   1. The origin of this software must not be misrepresented; you must not
	   claim that you wrote the original software. If you use this software
	   in a product, an acknowledgement in the product documentation would be
	   appreciated but is not required.

	   2. Altered source versions must be plainly marked as such, and must not be
	   misrepresented as being the original software.

	   3. This notice may not be removed or altered from any source
	   distribution.
*/

#pragma once

#include "Canvas.hpp"

namespace KRE
{
	class CanvasOGL : public Canvas
	{
	public:
		CanvasOGL();
		virtual ~CanvasOGL();

		void blitTexture(const TexturePtr& tex, const rect& src, float rotation, const rect& dst, const ColorPtr& color) const override;
		void blitTexture(const MaterialPtr& mat, float rotation, const rect& dst, const ColorPtr& color) const override;
		void blitTexture(const MaterialPtr& mat, const rect& src, float rotation, const rect& dst, const ColorPtr& color) const override;

		void drawRect(const rect& r, const ColorPtr& fill_color, const ColorPtr& stroke_color=nullptr, float rotate=0) const override;
		void drawLine(const point& p1, const point& p2, const Color& color) const override;
		void drawCircle(const point& centre, double radius, const Color& color) const override;

		static CanvasPtr getInstance();
	private:
		DISALLOW_COPY_AND_ASSIGN(CanvasOGL);
		void handleDimensionsChanged() override;
		glm::mat4 mvp_;
	};
}

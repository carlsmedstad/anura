/*
	Copyright (C) 2003-2014 by David White <davewx7@gmail.com>
	
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

#include "widget.hpp"

namespace gui
{
	class ScrollBarWidget : public Widget
	{
	public:
		explicit ScrollBarWidget(std::function<void(int)> handler);
		explicit ScrollBarWidget(const variant& v, game_logic::FormulaCallable* e);

		void set_range(int total_height, int window_height);
		void setLoc(int x, int y);
		void setDim(int w, int h);
		void set_window_pos(int pos) { window_pos_ = pos; }
		void set_step(int step) { step_ = step; }
		void set_arrow_step(int step) { arrow_step_ = step; }
		int window_pos() const { return window_pos_; }
	protected:
		virtual void setValue(const std::string& key, const variant& v);
		virtual variant getValue(const std::string& key) const;
	private:
		void handleDraw() const override;
		bool handleEvent(const SDL_Event& event, bool claimed) override;

		void down_button_pressed();
		void up_button_pressed();

		void clip_window_position();

		std::function<void(int)> handler_;
		WidgetPtr up_arrow_, down_arrow_, handle_, handle_bot_, handle_top_, background_;
		int window_pos_, window_size_, range_, step_, arrow_step_;

		bool dragging_handle_;
		int drag_start_;
		int drag_anchor_y_;

		game_logic::formula_ptr ffl_handler_;
		void handler_delegate(int);
	};

	typedef boost::intrusive_ptr<ScrollBarWidget> ScrollbarWidgetPtr;

}

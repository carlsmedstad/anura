/*
	Copyright (C) 2003-2014 by Kristina Simpson <sweet.kristas@gmail.com>
	
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

#include <functional>
#include <memory>
#include <string>
#include "Util.hpp"

namespace KRE
{
	class ShaderProgram;
	typedef std::shared_ptr<ShaderProgram> ShaderProgramPtr;

	class ActivesHandle
	{
	public:
		ActivesHandle();
		virtual ~ActivesHandle();
	private:
	};
	typedef std::shared_ptr<ActivesHandle> ActivesHandlePtr;

	/*
	class DrawCommand
	{
	public:
		typedef std::function<const void*(AttributeDesc::VariableType*, unsigned* cnt)> ValueType;
		DrawCommand(ActivesHandlePtr handle, ValueType node, bool incr=false)
			: handle_(handle),
			node_(node),
			incr_(incr)
		{
		}
		ActivesHandlePtr getActiveHandle() const { return handle_; }
		variant node() const { return node_; }
		bool shouldIncrement() const { return incr_; }
	private:
		ActivesHandlePtr handle_;
		ValueType node_;
		bool incr_;
	};*/

	class ShaderProgram
	{
	public:
		ShaderProgram();
		virtual ~ShaderProgram();

		virtual ActivesHandlePtr getHandle(const std::string& name) = 0;

		virtual void setUniform(ActivesHandlePtr active, const void*) = 0;
		virtual void setAttribute(ActivesHandlePtr active, const void*) = 0;

		virtual void makeActive() = 0;

		virtual void applyActives() = 0;

		//! Look-up the given shader program name in the list and return it.
		static ShaderProgramPtr getProgram(const std::string& name);
		//! loads the internal store of shader programs from the given file.
		static void loadFromFile(const std::string& filename);
	private:
		DISALLOW_COPY_AND_ASSIGN(ShaderProgram);
	};
}

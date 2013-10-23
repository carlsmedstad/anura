/*
	Copyright (C) 2003-2013 by David White <davewx7@gmail.com>
	
	This software is provided 'as-is', without any express or implied
	warranty. In no event will the authors be held liable for any damages
	arising from the use of this software.

	Permission is granted to anyone to use this software for any purpose,
	including commercial applications, and to alter it and redistribute it
	freely, subject to the following restrictions:

	   1. The origin of this software must not be misrepresented; you must not
	   claim that you wrote the original software. If you use this software
	   in a product, an acknowledgment in the product documentation would be
	   appreciated but is not required.

	   2. Altered source versions must be plainly marked as such, and must not be
	   misrepresented as being the original software.

	   3. This notice may not be removed or altered from any source
	   distribution.
*/

#pragma once

#if defined(USE_LUA)

#include <memory>
#include <lua.hpp>

#include "formula_callable.hpp"
#include "formula_callable_definition.hpp"

namespace lua
{
	class lua_compiled : public game_logic::formula_callable
	{
	public:
		lua_compiled();
		virtual ~lua_compiled();

		void reset_chunks();
		void add_chunk(const void* p, size_t sz);
		bool run(lua_State* L) const;

		const std::vector<char>& current() const;
		void next();
	private:
		DECLARE_CALLABLE(lua_compiled);

		typedef std::vector<std::vector<char>> chunk_list_type;
		chunk_list_type chunks_;
		mutable chunk_list_type::const_iterator chunks_it_;
	};
	typedef boost::intrusive_ptr<lua_compiled> lua_compiled_ptr;

	class lua_context
	{
	public:
		lua_context();
		explicit lua_context(game_logic::formula_callable& callable);
		virtual ~lua_context();

		static lua_context& get_instance();

		std::shared_ptr<lua_State>& context() { return state_; }
		lua_State* context_ptr() { return state_.get(); }

		void set_self_callable(game_logic::formula_callable& callable);

		bool execute(const variant& value, game_logic::formula_callable* callable=NULL);

		bool dostring(const std::string&name, const std::string& str, game_logic::formula_callable* callable=NULL);
		bool dofile(const std::string&name, const std::string& str, game_logic::formula_callable* callable=NULL);

		lua_compiled_ptr compile(const std::string& name, const std::string& str);
	private:
		void init();

		std::shared_ptr<lua_State> state_;
	};
}

#endif

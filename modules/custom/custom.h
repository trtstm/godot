/*************************************************************************/
/*  custom.h                                                             */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                    http://www.godotengine.org                         */
/*************************************************************************/
/* Copyright (c) 2007-2016 Juan Linietsky, Ariel Manzur.                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/
#ifndef CUSTOM_H
#define CUSTOM_H

#include "script_language.h"
#include "io/resource_loader.h"
#include "io/resource_saver.h"
#include "os/thread.h"
#include "pair.h"

class Custom : public Script {


	OBJ_TYPE(Custom,Script);

public:
	Custom();
	~Custom();

	virtual bool can_instance() const;

	virtual StringName get_instance_base_type() const; // this may not work in all scripts, will return empty if so
	virtual ScriptInstance* instance_create(Object *p_this);
	virtual bool instance_has(const Object *p_this) const;

	
	virtual bool has_source_code() const;
	virtual String get_source_code() const;
	virtual void set_source_code(const String& p_code);
	virtual Error reload();

	virtual bool is_tool() const;

	virtual String get_node_type() const;

	virtual ScriptLanguage *get_language() const;

	virtual bool has_script_signal(const StringName& p_signal) const;
	virtual void get_script_signal_list(List<MethodInfo> *r_signals) const;

	virtual bool get_property_default_value(const StringName& p_property,Variant& r_value) const;

	virtual void update_exports(); //editor tool
};

class CustomLanguage : public ScriptLanguage {
	friend class Custom;

	static CustomLanguage *singleton;

	static CustomLanguage *get_singleton();

public:
	CustomLanguage();

	virtual String get_name() const;
	
	/* LANGUAGE FUNCTIONS */
	virtual void init();	
	virtual String get_type() const;
	virtual String get_extension() const;
	virtual Error execute_file(const String& p_path);	
	virtual void finish();	

	/* EDITOR FUNCTIONS */
	virtual void get_reserved_words(List<String> *p_words) const;
	virtual void get_comment_delimiters(List<String> *p_delimiters) const;
	virtual void get_string_delimiters(List<String> *p_delimiters) const;
	virtual String get_template(const String& p_class_name, const String& p_base_class_name) const;
	virtual bool validate(const String& p_script, int &r_line_error,int &r_col_error,String& r_test_error, const String& p_path="",List<String> *r_functions=NULL) const;
	virtual Script *create_script() const;
	virtual bool has_named_classes() const;
	virtual int find_function(const String& p_function,const String& p_code) const;
	virtual String make_function(const String& p_class,const String& p_name,const StringArray& p_args) const;
	virtual Error complete_code(const String& p_code, const String& p_base_path, Object*p_owner,List<String>* r_options,String& r_call_hint);
	virtual void auto_indent_code(String& p_code,int p_from_line,int p_to_line) const;
	virtual void add_global_constant(const StringName& p_variable,const Variant& p_value);

	/* DEBUGGER FUNCTIONS */

	virtual String debug_get_error() const;
	virtual int debug_get_stack_level_count() const;
	virtual int debug_get_stack_level_line(int p_level) const;
	virtual String debug_get_stack_level_function(int p_level) const;
	virtual String debug_get_stack_level_source(int p_level) const;
	virtual void debug_get_stack_level_locals(int p_level,List<String> *p_locals, List<Variant> *p_values, int p_max_subitems=-1,int p_max_depth=-1);
	virtual void debug_get_stack_level_members(int p_level,List<String> *p_members, List<Variant> *p_values, int p_max_subitems=-1,int p_max_depth=-1);
	virtual void debug_get_globals(List<String> *p_locals, List<Variant> *p_values, int p_max_subitems=-1,int p_max_depth=-1);
	virtual String debug_parse_stack_level_expression(int p_level,const String& p_expression,int p_max_subitems=-1,int p_max_depth=-1);


	//virtual Vector<StackInfo> debug_get_current_stack_info();

	/* LOADER FUNCTIONS */

	virtual void get_recognized_extensions(List<String> *p_extensions) const;
	virtual void get_public_functions(List<MethodInfo> *p_functions) const;
	virtual void get_public_constants(List<Pair<String,Variant> > *p_constants) const;

	virtual void frame();

	virtual ~CustomLanguage();
};

#endif // GD_SCRIPT_H

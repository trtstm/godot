/*************************************************************************/
/*  gd_script.cpp                                                        */
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
#include <iostream>

#include "custom.h"
#include "globals.h"
#include "global_constants.h"
#include "os/file_access.h"
#include "io/file_access_encrypted.h"


Custom::Custom()
{
	//std::cout << "Custom::Custom" << std::endl;
}

Custom::~Custom()
{
	//std::cout << "Custom::~Custom" << std::endl;
}

// TODO: check whether we can instance or not
bool Custom::can_instance() const
{
	//std::cout << "Custom::can_instance" << std::endl;
	return true;
}

StringName Custom::get_instance_base_type() const
{
	//std::cout << "Custom::get_instance_base_type" << std::endl;
	return StringName();
}

ScriptInstance* Custom::instance_create(Object *p_this)
{
	std::cout << "Custom::instance_create" << std::endl;
	ERR_EXPLAIN(p_this->get_type_name());
	ERR_FAIL_V(NULL);
	return NULL;
}

bool Custom::instance_has(const Object *p_this) const
{
	std::cout << "Custom::instance_has" << std::endl;
	ERR_EXPLAIN(p_this->get_type_name());
	ERR_FAIL_V(NULL);
	return false;
}

	
bool Custom::has_source_code() const
{
	//std::cout << "Custom::has_source_code" << std::endl;
	return source != "";
}

String Custom::get_source_code() const
{
	//std::cout << "Custom::get_source_code" << std::endl;
	return source;
}

// Source code for our script
void Custom::set_source_code(const String& p_code)
{
	//std::cout << "Custom::set_source_code" << std::endl;
	source = p_code;
}

Error Custom::reload()
{
	std::cout << "Custom::reload" << std::endl;
	return OK;
}

bool Custom::is_tool() const
{
	//std::cout << "Custom::is_tool" << std::endl;
	return false;
}

String Custom::get_node_type() const
{
	std::cout << "Custom::get_node_type" << std::endl;
	return "";
}

ScriptLanguage *Custom::get_language() const
{
	//std::cout << "Custom::get_language" << std::endl;
	return CustomLanguage::get_singleton();
}

bool Custom::has_script_signal(const StringName& p_signal) const
{
	//std::cout << "Custom::has_script_signal" << std::endl;
	return false;
}

void Custom::get_script_signal_list(List<MethodInfo> *r_signals) const
{
	//std::cout << "Custom::get_script_signal_list" << std::endl;
}

bool Custom::get_property_default_value(const StringName& p_property,Variant& r_value) const
{
	std::cout << "Custom::get_property_default_value" << std::endl;
	return false;
}

void Custom::update_exports() {}

// ---------------------------------------------
CustomLanguage *CustomLanguage::singleton = NULL;
const char* CustomLanguage::extension = "cus";

CustomLanguage::CustomLanguage()
{
	//std::cout << "CustomLanguage::CustomLanguage" << std::endl;
	singleton = this;
}

CustomLanguage::~CustomLanguage()
{
	//std::cout << "CustomLanguage::~CustomLanguage" << std::endl;
	singleton = NULL;
}

CustomLanguage *CustomLanguage::get_singleton()
{
	//std::cout << "CustomLanguage::get_singleton" << std::endl;
	return singleton;
}

// Name of our language. E.g what shows up in the editor?
String CustomLanguage::get_name() const
{
	//std::cout << "CustomLanguage::get_name" << std::endl;
	return "CustomLanguage";
}
	
	/* LANGUAGE FUNCTIONS */
void CustomLanguage::init()
{
	//std::cout << "CustomLanguage::init" << std::endl;
}

// Same as name?
String CustomLanguage::get_type() const
{
	//std::cout << "CustomLanguage::get_type" << std::endl;
	return "CustomLanguage";
}

// What extension does this script use.
String CustomLanguage::get_extension() const
{
	//std::cout << "CustomLanguage::get_extension" << std::endl;
	return extension;
}

Error CustomLanguage::execute_file(const String& p_path)
{
	std::cout << "CustomLanguage::execute_file" << std::endl;
	return OK;
}

void CustomLanguage::finish()
{
	std::cout << "CustomLanguage::finish" << std::endl;
}	

	/* EDITOR FUNCTIONS */
void CustomLanguage::get_reserved_words(List<String> *p_words) const
{
	//std::cout << "CustomLanguage::get_reserved_words" << std::endl;
}

	
// TODO: add the real stuff
void CustomLanguage::get_comment_delimiters(List<String> *p_delimiters) const
{
	//std::cout << "CustomLanguage::get_comment_delimiters" << std::endl;
	p_delimiters->push_back("//");
}

// TODO: add the real stuff
void CustomLanguage::get_string_delimiters(List<String> *p_delimiters) const
{
	//std::cout << "CustomLanguage::get_string_delimiters" << std::endl;
	p_delimiters->push_back("\" \"");
}

// Template that can be used in the editor.
String CustomLanguage::get_template(const String& p_class_name, const String& p_base_class_name) const
{
	//std::cout << "CustomLanguage::get_template" << std::endl;
	return "This is a template with p_class_name: '" + p_class_name + "' and p_base_class_name '" + p_base_class_name;
}

// TODO: do some real checking
bool CustomLanguage::validate(const String& p_script, int &r_line_error,int &r_col_error,String& r_test_error, const String& p_path,List<String> *r_functions) const
{
	//std::cout << "CustomLanguage::validate" << std::endl;
	return true;
}

// Create a script. E.g someone clicked on new script in the editor.
Script *CustomLanguage::create_script() const
{
	//std::cout << "CustomLanguage::create_script" << std::endl;
	return memnew(Custom);
}

// Whether a class has a name. In gdscript there are no names. A file is a class.
bool CustomLanguage::has_named_classes() const
{
	//std::cout << "CustomLanguage::has_named_classes" << std::endl;
	return false;
}

int CustomLanguage::find_function(const String& p_function,const String& p_code) const
{
	std::cout << "CustomLanguage::find_function" << std::endl;
	return 0;
}

String CustomLanguage::make_function(const String& p_class,const String& p_name,const StringArray& p_args) const
{
	std::cout << "CustomLanguage::make_function" << std::endl;
	return "";
}

Error CustomLanguage::complete_code(const String& p_code, const String& p_base_path, Object*p_owner,List<String>* r_options,String& r_call_hint)
{
	//std::cout << "CustomLanguage::complete_code" << std::endl;
	return ERR_UNAVAILABLE;
}

void CustomLanguage::auto_indent_code(String& p_code,int p_from_line,int p_to_line) const
{
	//std::cout << "CustomLanguage::auto_indent_code" << std::endl;
}

void CustomLanguage::add_global_constant(const StringName& p_variable,const Variant& p_value)
{
	std::cout << "CustomLanguage::add_global_constant" << std::endl;
}

	/* DEBUGGER FUNCTIONS */

String CustomLanguage::debug_get_error() const
{
	std::cout << "CustomLanguage::debug_get_error" << std::endl;
	return "";
}

int CustomLanguage::debug_get_stack_level_count() const
{
	std::cout << "CustomLanguage::debug_get_stack_level_count" << std::endl;
	return 0;
}

int CustomLanguage::debug_get_stack_level_line(int p_level) const
{
	std::cout << "CustomLanguage::debug_get_stack_level_line" << std::endl;
	return 0;
}

String CustomLanguage::debug_get_stack_level_function(int p_level) const
{
	std::cout << "CustomLanguage::debug_get_stack_level_function" << std::endl;
	return "";
}

String CustomLanguage::debug_get_stack_level_source(int p_level) const
{
	std::cout << "CustomLanguage::debug_get_stack_level_source" << std::endl;
	return "";
}

void CustomLanguage::debug_get_stack_level_locals(int p_level,List<String> *p_locals, List<Variant> *p_values, int p_max_subitems,int p_max_depth)
{
	std::cout << "CustomLanguage::debug_get_stack_level_locals" << std::endl;
}

void CustomLanguage::debug_get_stack_level_members(int p_level,List<String> *p_members, List<Variant> *p_values, int p_max_subitems,int p_max_depth)
{
	std::cout << "CustomLanguage::debug_get_stack_level_members" << std::endl;
}
	
void CustomLanguage::debug_get_globals(List<String> *p_locals, List<Variant> *p_values, int p_max_subitems,int p_max_depth)
{
	std::cout << "CustomLanguage::debug_get_globals" << std::endl;
}

String CustomLanguage::debug_parse_stack_level_expression(int p_level,const String& p_expression,int p_max_subitems,int p_max_depth)
{
	std::cout << "CustomLanguage::debug_parse_stack_level_expression" << std::endl;
	return "";
}


	/* LOADER FUNCTIONS */
// The extensions we support loading.
void CustomLanguage::get_recognized_extensions(List<String> *p_extensions) const
{
	//std::cout << "CustomLanguage::get_recognized_extensions" << std::endl;
	p_extensions->push_back(extension);
}

void CustomLanguage::get_public_functions(List<MethodInfo> *p_functions) const
{
	std::cout << "CustomLanguage::get_public_functions" << std::endl;
}

void CustomLanguage::get_public_constants(List<Pair<String,Variant> > *p_constants) const
{
	std::cout << "CustomLanguage::get_public_constants" << std::endl;
}

// Called every frame. Can be used to profile our script per frame.
void CustomLanguage::frame()
{
	//std::cout << "CustomLanguage::frame" << std::endl;
}

// ---------------------------
// TODO: Load real code
RES ResourceFormatLoaderCustom::load(const String &p_path,const String& p_original_path,Error *r_error)
{
	std::cout << "ResourceFormatLoaderCustom::load" << std::endl;

	Custom *script = memnew( Custom );
	script->set_source_code("Source code from ResourceFormatLoader");
	Ref<Custom> scriptres(script);
	return scriptres;
}

// What extensions can we load.
void ResourceFormatLoaderCustom::get_recognized_extensions(List<String> *p_extensions) const
{
	//std::cout << "ResourceFormatLoaderCustom::get_recognized_extensions" << std::endl;
	p_extensions->push_back(CustomLanguage::extension);
}

// Can we handle this script type?
bool ResourceFormatLoaderCustom::handles_type(const String& p_type) const
{
	//std::cout << "ResourceFormatLoaderCustom::handles_type" << std::endl;
	return p_type == "CustomLanguage";
}

// file extension -> script type name.
String ResourceFormatLoaderCustom::get_resource_type(const String &p_path) const
{
	//std::cout << "ResourceFormatLoaderCustom::get_resource_type" << std::endl;
	String el = p_path.extension().to_lower();
	if (el==CustomLanguage::extension)
		return "CustomLanguage";
	return "";
}

// -----------------------
// Save the script to the file.
Error ResourceFormatSaverCustom::save(const String &p_path,const RES& p_resource,uint32_t p_flags)
{
	std::cout << "ResourceFormatSaverCustom::save" << std::endl;

	Ref<Custom> sqscr = p_resource;
	ERR_FAIL_COND_V(sqscr.is_null(),ERR_INVALID_PARAMETER);

	String source = sqscr->get_source_code();

	Error err;
	FileAccess *file = FileAccess::open(p_path,FileAccess::WRITE,&err);

	if (err) {

		ERR_FAIL_COND_V(err,err);
	}

	file->store_string(source);
	if (file->get_error()!=OK && file->get_error()!=ERR_FILE_EOF) {
		memdelete(file);
		return ERR_CANT_CREATE;
	}
	file->close();
	memdelete(file);
	return OK;
}

// TODO: ?
void ResourceFormatSaverCustom::get_recognized_extensions(const RES& p_resource,List<String> *p_extensions) const
{
	std::cout << "ResourceFormatSaverCustom::get_recognized_extensions" << std::endl;
	if (p_resource->cast_to<Custom>()) {
		p_extensions->push_back(CustomLanguage::extension);
	}
}

// Check if we can save this resource.
bool ResourceFormatSaverCustom::recognize(const RES& p_resource) const
{
	std::cout << "ResourceFormatSaverCustom::recognize" << std::endl;
	return p_resource->cast_to<Custom>() != NULL;
}


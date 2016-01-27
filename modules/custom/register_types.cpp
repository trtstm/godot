/*************************************************/
/*  register_script_types.cpp                    */
/*************************************************/
/*            This file is part of:              */
/*                GODOT ENGINE                   */
/*************************************************/
/*       Source code within this file is:        */
/*  (c) 2007-2016 Juan Linietsky, Ariel Manzur   */
/*             All Rights Reserved.              */
/*************************************************/

#include <iostream>

#include "custom.h"
#include "register_types.h"

#include "io/resource_loader.h"
#include "os/file_access.h"
#include "io/file_access_encrypted.h"

CustomLanguage *script_language=NULL;


#ifdef TOOLS_ENABLED

#include "tools/editor/editor_import_export.h"
#include "tools/editor/editor_node.h"
#include "tools/editor/editor_settings.h"

class EditorExportCustom : public EditorExportPlugin {

	OBJ_TYPE(EditorExportCustom,EditorExportPlugin);

public:

	virtual Vector<uint8_t> custom_export(String& p_path,const Ref<EditorExportPlatform> &p_platform) {
		std::cout << "EditorExportCustom::custom_export" << std::endl;

		return Vector<uint8_t>();
	}


	EditorExportCustom(){}

};

static void register_editor_plugin() {

	std::cout << "register_editor_plugin" << std::endl;
	Ref<EditorExportCustom> egd = memnew( EditorExportCustom );
	EditorImportExport::get_singleton()->add_export_plugin(egd);
}


#endif

void register_custom_types() {
	std::cout << "register_custom_types" << std::endl;
	ObjectTypeDB::register_type<Custom>();

	script_language=memnew( CustomLanguage );
	//script_language_gd->init();
	ScriptServer::register_language(script_language);

#ifdef TOOLS_ENABLED

	EditorNode::add_init_callback(register_editor_plugin);
#endif

}
void unregister_custom_types() {

	if (script_language)
		memdelete( script_language );

}

function(target_add_versioninfo target)
	cmake_parse_arguments(target_add_versioninfo "" "VERSION;COMPANY_NAME;PRODUCT_NAME;FILE_NAME;FILE_DESCRIPTION;LANG_ID;CHARSET_ID" "" ${ARGN})

	# Required arguments
	if (NOT DEFINED target_add_versioninfo_VERSION)
		message(SEND_ERROR "target_add_versioninfo: function requires VERSION argument")
		return()
	endif()

	if (NOT DEFINED target_add_versioninfo_COMPANY_NAME)
		message(SEND_ERROR "target_add_versioninfo: function requires COMPANY_NAME argument")
		return()
	else()
		set(company_name ${target_add_versioninfo_COMPANY_NAME})
	endif()

	if (NOT DEFINED target_add_versioninfo_PRODUCT_NAME)
		message(SEND_ERROR "target_add_versioninfo: function requires PRODUCT_NAME argument")
		return()
	else()
		set(product_name ${target_add_versioninfo_PRODUCT_NAME})
	endif()

	# Optional arguments
	if (DEFINED target_add_versioninfo_FILE_NAME)
		set(file_name ${target_add_versioninfo_FILE_NAME})
	else()
		get_target_property(file_name ${target} OUTPUT_NAME)

		if (file_name STREQUAL "file_name-NOTFOUND")
			get_target_property(file_name ${target} NAME)
		endif()
	endif()

	if (DEFINED target_add_versioninfo_FILE_DESCRIPTION)
		set(file_description ${target_add_versioninfo_FILE_DESCRIPTION})
	else()
		set(file_description ${product_name})
	endif()

	if (DEFINED target_add_versioninfo_LANG_ID)
		set(lang_id ${target_add_versioninfo_LANG_ID})
	else()
		set(lang_id "400")
	endif()

	if (DEFINED target_add_versioninfo_CHARSET_ID)
		set(charset_id ${target_add_versioninfo_CHARSET_ID})
	else()
		set(charset_id "4b0")
	endif()

	math(EXPR charset_id_int "0x${charset_id}")

	# Parse VERSION argument
	string(REPLACE "." ";" version_list "${target_add_versioninfo_VERSION}")
	list(LENGTH version_list version_list_length)

	if (version_list_length LESS 0 OR version_list_length GREATER 4)
		message(SEND_ERROR "target_add_versioninfo: function requires VERSION argument to have version components within the range <2, 4>")
		return()
	endif()

	list(GET version_list 0 version_major)
	if (NOT version_major MATCHES "^[0-9]+$")
		message(SEND_ERROR "target_add_versioninfo: function requires VERSION.MAJOR to be an integer!")
		return()
	endif()

	list(GET version_list 1 version_minor)
	if (NOT version_minor MATCHES "^[0-9]+$")
		message(SEND_ERROR "target_add_versioninfo: function VERSION.MINOR to be an integer!")
		return()
	endif()

	if (${version_list_length} GREATER_EQUAL 3)
		list(GET version_list 2 version_patch)
		if (NOT version_patch MATCHES "^[0-9]+$")
			message(SEND_ERROR "target_add_versioninfo: function VERSION.PATCH to be an integer!")
			return()
		endif()
	else()
		set(version_patch 0)
	endif()

	if (${version_list_length} EQUAL 4)
		list(GET version_list 3 version_build)
		if (NOT version_build MATCHES "^[0-9]+$")
			message(SEND_ERROR "target_add_versioninfo: function VERSION.BUILD to be an integer!")
			return()
		endif()
	else()
		set(version_build 0)
	endif()

	# Extract file_type from target
	get_target_property(target_type ${target} TYPE)

	if(target_type STREQUAL "EXECUTABLE")
		set(file_type 0x1L)

		if (NOT DEFINED target_add_versioninfo_FILE_NAME)
			set(file_name "${file_name}.exe")
		endif()
	elseif(target_type STREQUAL "STATIC_LIBRARY")
		set(file_type 0x7L)

		if (NOT DEFINED target_add_versioninfo_FILE_NAME)
			set(file_name "${file_name}.lib")
		endif()
	elseif(target_type STREQUAL "SHARED_LIBRARY")
		set(file_type 0x2L)

		if (NOT DEFINED target_add_versioninfo_FILE_NAME)
			set(file_name "${file_name}.dll")
		endif()
	else()
		set(file_type 0x0L)
	endif()

	# Get current year
	string(TIMESTAMP year "%Y")

	# Generate versioninfo.rc for specific target
	configure_file("${CMAKE_CURRENT_FUNCTION_LIST_DIR}/version.rc.in" "${CMAKE_CURRENT_BINARY_DIR}/version.rc" @ONLY)

	# Add generated versioninfo.rc as target source file
	target_sources(${target} PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/version.rc" )
endfunction()

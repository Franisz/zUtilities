# union-api

file(GLOB_RECURSE SRC
	"union-api/*.cpp"
)

add_library(union-api STATIC)
target_sources(union-api PRIVATE ${SRC})

set_target_properties(union-api PROPERTIES
	OUTPUT_NAME "UnionApi"
)

target_compile_definitions(union-api
	PUBLIC
		_UNION_API_LIB
	PRIVATE
		_UNION_API_BUILD
)

target_include_directories(union-api PUBLIC "union-api/union-api")
target_link_directories(union-api PUBLIC "union-api/union-api")

# gothic-api

file(GLOB_RECURSE SRC 
    "gothic-api/*.cpp"
)

add_library(gothic-api INTERFACE)
target_sources(gothic-api INTERFACE ${SRC})

target_include_directories(gothic-api 
	INTERFACE
		"gothic-api/"
		"gothic-userapi/"
)

target_link_directories(gothic-api 
	INTERFACE 
		"gothic-api/"
)

# union

add_library(union INTERFACE)
target_link_libraries(union INTERFACE gothic-api union-api)
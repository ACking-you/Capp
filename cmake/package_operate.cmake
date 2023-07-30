# Used to add package with url
macro(add_package name git_url tag)
    CPMAddPackage(
            ${name}
            GIT_REPOSITORY ${git_url}
            GIT_TAG ${tag}
            GIT_SHALLOW TRUE
    )
endmacro()

# Used to add lib to targets
macro(targets_link_package package_target_name)
    foreach (target ${ARGN})
        message(STATUS "Add ${package_target_name} for test:${target}")
        target_link_libraries(${target} ${package_target_name})
    endforeach ()
endmacro()
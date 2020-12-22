function(set_version_script_path script_path)
  set(EMF_VERSION_MANAGEMENT_SCRIPT
      "${script_path}"
      PARENT_SCOPE)
endfunction()

function(extract_version version output)
  execute_process(
    COMMAND "${Python3_EXECUTABLE}" "${EMF_VERSION_MANAGEMENT_SCRIPT}" extract
            "${version}" -
    OUTPUT_VARIABLE version_tmp
    OUTPUT_STRIP_TRAILING_WHITESPACE)

  set(${output}
      ${version_tmp}
      PARENT_SCOPE)
endfunction()

function(replace_version input output version)
  get_filename_component(output_dir ${output} DIRECTORY)

  if(NOT EXISTS ${output_dir})
    file(MAKE_DIRECTORY ${output_dir})
  endif()

  execute_process(
    COMMAND "${Python3_EXECUTABLE}" "${EMF_VERSION_MANAGEMENT_SCRIPT}" replace
            "${input}" "${output}" "${version}" ${ARGN})
endfunction()

function(monitor_version target input output version)
  replace_version(${input} ${output} ${version} ${ARGN})

  add_custom_command(
    OUTPUT "${output}"
    COMMAND "${Python3_EXECUTABLE}" "${EMF_VERSION_MANAGEMENT_SCRIPT}" replace
            "${input}" "${output}" "${version}" ${ARGN}
    DEPENDS "${input}")

  add_custom_target(${target} DEPENDS "${output}")
endfunction()

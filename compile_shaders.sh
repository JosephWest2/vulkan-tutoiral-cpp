source_directory="./src/shaders"
output_directory="./bin/shaders"
glslc "$source_directory/simple_shader.vert" -o "$output_directory/simple_shader.vert.spv"
glslc "$source_directory/simple_shader.frag" -o "$output_directory/simple_shader.frag.spv"

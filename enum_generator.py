import sys

enum_name = sys.argv[1]

input_filename = "in.txt"
output_filename = "out.txt"

with open(input_filename) as in_file:
    with open(output_filename, "w") as out_file:
        lines = [line.rstrip() for line in in_file]

        out_file.write("enum class %s {\n" % (enum_name))
        for line in lines:
            out_file.write("%s,\n" % (line))
        out_file.write("};\n")

        out_file.write("NLOHMANN_JSON_SERIALIZE_ENUM(%s,{\n" % (enum_name))
        for line in lines:
            out_file.write('{%s::%s, "%s"},\n' % (enum_name, line, line))
        out_file.write("})\n")

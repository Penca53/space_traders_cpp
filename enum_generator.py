import sys
from re import sub

enum_name = sys.argv[1]

input_filename = "in.txt"
output_filename = "out.txt"


def to_camel_case(s):
    s = sub(r"(_|-)+", " ", s).title().replace(" ", "").replace("*", "")
    return "k" + "".join([s[0].upper(), s[1:]])


with open(input_filename) as in_file:
    with open(output_filename, "w") as out_file:
        lines = [line.rstrip() for line in in_file]

        out_file.write("enum class %s {\n" % (enum_name))
        for line in lines:
            out_file.write("%s,\n" % (to_camel_case(line)))
        out_file.write("};\n")

        out_file.write("NLOHMANN_JSON_SERIALIZE_ENUM(%s,{\n" % (enum_name))
        for line in lines:
            out_file.write('{%s::%s, "%s"},\n' % (enum_name, to_camel_case(line), line))
        out_file.write("})\n")

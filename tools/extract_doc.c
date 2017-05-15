#include "uclib/str.h"
#include "uclib/file.h"

static void extract(const char* input_filename, const char* output_filename) {
    str_t* out = str_create(NULL, 0, 0);
    str_t* str = str_create(NULL, 0, 0);

    if(file_read_text(input_filename, str)) {
        const char* p = strstr(str->str, "/**");
        while(p != NULL) {
            const char* end = strstr(p, "*/");
            break_if_fail(end != NULL);
            str_append(out, p, end-p+3); 
            
            p = strstr(end, "/**");
        }
    }
    file_write_text(output_filename, out->str);

    str_unref(str);
    str_unref(out);
}

int main(int argc, char* argv[]) {
    const char* input_filename = NULL;
    const char* output_dir = NULL;
    
    str_t* output_filename = NULL;
    str_t* basename = NULL;

    if(argc < 3) {
        printf("Usage: %s input-file output-dir\n", argv[0]);
        return 0;
    }

    input_filename = argv[1];
    output_dir = argv[2];
    
    output_filename = str_create(NULL, 0, 512);
    basename = str_create(NULL, 0, 0);

    str_basename(basename, input_filename, FALSE);
    str_append_f(output_filename, "%s/%s.js", output_dir, basename->str);

    extract(input_filename, output_filename->str);

    str_unref(basename);
    str_unref(output_filename);

    return 0;
}

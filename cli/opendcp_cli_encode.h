
#ifndef _OPENDCP_CLI_ENCODE_H_
#define _OPENDCP_CLI_ENCODE_H_

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_POSITIONALS 64

typedef struct {
    /* commands */
    int j2k;
    int mxf;
    int stereoscopic;
    /* arguments */
    char *input;
    char *input_left;
    char *input_right;
    char *output;
    char *output_left;
    char *output_right;
    /* flags */
    int no_overwrite;
    int no_xyz;
    int resize;
    /* options */
    char *bw;
    char *colorspace;
    char *encoder;
    char *profile;
    char *rate;
    char *type;
    char *start;
    char *end;
    char *slideshow;
    char *log_level;
    char *key;
    char *key_id;
    char *threads;
    char *tmp_dir;
    /* special */
    const char *usage;
} opendcp_args_t;

typedef struct {
    const char *name;
    int         value;
} command_t;

typedef struct {
    const char *name;
    char       *value;
} argument_t;

typedef struct {
    const char *name;
    int         value_required;
    char       *value;
} option_t;

typedef struct {
    char *name;
} positional_t;

typedef struct {
    int           n_commands;
    int           n_arguments;
    int           n_options;
    int           n_positional;
    command_t    *commands;
    argument_t   *arguments;
    option_t     *options;
    positional_t *positionals;
} cli_t;

typedef struct {
    int argc;
    char **argv;
    int i;
    char *current;
} argv_t;

int opendcp_command_j2k(opendcp_t *opendcp, opendcp_args_t *args);

#ifdef __cplusplus
}
#endif

#endif // _OPENDCP_CLI_ENCODE_H_

/** @file cmdline.h
 *  @brief The header file for the command line option parser
 *  generated by GNU Gengetopt version 2.21
 *  http://www.gnu.org/software/gengetopt.
 *  DO NOT modify this file, since it can be overwritten
 *  @author GNU Gengetopt by Lorenzo Bettini */

#ifndef CMDLINE_H
#define CMDLINE_H

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef CMDLINE_PARSER_PACKAGE
/** @brief the program name */
#define CMDLINE_PARSER_PACKAGE PACKAGE
#endif

#ifndef CMDLINE_PARSER_VERSION
/** @brief the program version */
#define CMDLINE_PARSER_VERSION VERSION
#endif

/** @brief Where the command line options are stored */
struct gengetopt_args_info
{
  const char *help_help; /**< @brief Print help and exit help description.  */
  const char *version_help; /**< @brief Print version and exit help description.  */
  int invert_test_flag;	/**< @brief TEST pin is inverted (default=off).  */
  const char *invert_test_help; /**< @brief TEST pin is inverted help description.  */
  int invert_reset_flag;	/**< @brief RESET pin is inverted (default=off).  */
  const char *invert_reset_help; /**< @brief RESET pin is inverted help description.  */
  int telosb_flag;	/**< @brief Assume a TelosB node (default=off).  */
  const char *telosb_help; /**< @brief Assume a TelosB node help description.  */
  int tmote_flag;	/**< @brief Assume a Tmote node (default=off).  */
  const char *tmote_help; /**< @brief Assume a Tmote node help description.  */
  int debug_flag;	/**< @brief be verbose for debug purposes (default=off).  */
  const char *debug_help; /**< @brief be verbose for debug purposes help description.  */
  int f1x_flag;	/**< @brief Specify CPU family (default=off).  */
  const char *f1x_help; /**< @brief Specify CPU family help description.  */
  int intelhex_flag;	/**< @brief force fileformat to be IntelHex (default=off).  */
  const char *intelhex_help; /**< @brief force fileformat to be IntelHex help description.  */
  int erase_flag;	/**< @brief erase device (default=off).  */
  const char *erase_help; /**< @brief erase device help description.  */
  int reset_flag;	/**< @brief reset device (default=off).  */
  const char *reset_help; /**< @brief reset device help description.  */
  char * program_arg;	/**< @brief program file.  */
  char * program_orig;	/**< @brief program file original value given at command line.  */
  const char *program_help; /**< @brief program file help description.  */
  char * comport_arg;	/**< @brief communicate using this device.  */
  char * comport_orig;	/**< @brief communicate using this device original value given at command line.  */
  const char *comport_help; /**< @brief communicate using this device help description.  */
  
  int help_given ;	/**< @brief Whether help was given.  */
  int version_given ;	/**< @brief Whether version was given.  */
  int invert_test_given ;	/**< @brief Whether invert-test was given.  */
  int invert_reset_given ;	/**< @brief Whether invert-reset was given.  */
  int telosb_given ;	/**< @brief Whether telosb was given.  */
  int tmote_given ;	/**< @brief Whether tmote was given.  */
  int debug_given ;	/**< @brief Whether debug was given.  */
  int f1x_given ;	/**< @brief Whether f1x was given.  */
  int intelhex_given ;	/**< @brief Whether intelhex was given.  */
  int erase_given ;	/**< @brief Whether erase was given.  */
  int reset_given ;	/**< @brief Whether reset was given.  */
  int program_given ;	/**< @brief Whether program was given.  */
  int comport_given ;	/**< @brief Whether comport was given.  */

} ;

/** @brief The additional parameters to pass to parser functions */
struct cmdline_parser_params
{
  int override; /**< @brief whether to override possibly already present options (default 0) */
  int initialize; /**< @brief whether to initialize the option structure gengetopt_args_info (default 0) */
  int check_required; /**< @brief whether to check that all required options were provided (default 0) */
  int check_ambiguity; /**< @brief whether to check for options already specified in the option structure gengetopt_args_info (default 0) */
} ;

/** @brief the purpose string of the program */
extern const char *gengetopt_args_info_purpose;
/** @brief the usage string of the program */
extern const char *gengetopt_args_info_usage;
/** @brief all the lines making the help output */
extern const char *gengetopt_args_info_help[];

/**
 * The command line parser
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser (int argc, char * const *argv,
  struct gengetopt_args_info *args_info);

/**
 * The command line parser (version with additional parameters - deprecated)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param override whether to override possibly already present options
 * @param initialize whether to initialize the option structure my_args_info
 * @param check_required whether to check that all required options were provided
 * @return 0 if everything went fine, NON 0 if an error took place
 * @deprecated use cmdline_parser_ext() instead
 */
int cmdline_parser2 (int argc, char * const *argv,
  struct gengetopt_args_info *args_info,
  int override, int initialize, int check_required);

/**
 * The command line parser (version with additional parameters)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param params additional parameters for the parser
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_ext (int argc, char * const *argv,
  struct gengetopt_args_info *args_info,
  struct cmdline_parser_params *params);

/**
 * Save the contents of the option struct into a (text) file.
 * This file can be read by the config file parser (if generated by gengetopt)
 * @param filename the file where to save
 * @param args_info the option struct to save
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_file_save(const char *filename,
  struct gengetopt_args_info *args_info);

/**
 * Print the help
 */
void cmdline_parser_print_help(void);
/**
 * Print the version
 */
void cmdline_parser_print_version(void);

/**
 * Allocates dynamically a cmdline_parser_params structure and initializes
 * all its fields to 0
 * @return the initialized cmdline_parser_params structure
 */
struct cmdline_parser_params *cmdline_parser_params_init();

/**
 * Initializes the passed gengetopt_args_info structure's fields
 * (also set default values for options that have a default)
 * @param args_info the structure to initialize
 */
void cmdline_parser_init (struct gengetopt_args_info *args_info);
/**
 * Deallocates the string fields of the gengetopt_args_info structure
 * (but does not deallocate the structure itself)
 * @param args_info the structure to deallocate
 */
void cmdline_parser_free (struct gengetopt_args_info *args_info);

/**
 * Checks that all the required options were specified
 * @param args_info the structure to check
 * @param prog_name the name of the program that will be used to print
 *   possible errors
 * @return
 */
int cmdline_parser_required (struct gengetopt_args_info *args_info,
  const char *prog_name);


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* CMDLINE_H */
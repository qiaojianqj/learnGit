#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
/* ENVIRON 变量包含了整个环境。*/
extern char **environ;

/* 程序的名称。*/
const char *program_name;
/* 将程序使用方法输出到 STREAM 中(通常为 stdout 或 stderr),并以 EXIT_CODE 为返回
 * 值退出程序。函数调用不会返回。*/
void print_usage(FILE *stream, int exit_code) {
  fprintf(stream, "Usage : %s options[inputfile...]\n", program_name);
  fprintf(stream, " -h --help Display this usage information.\n"
                  " -o --output filename Write output to file.\n"
                  " -v --verbose Print verbose messages.\n");
  exit(exit_code);
}

/* 程序主入口点。ARGC 包含了参数列表中元素的数量;ARGV
 * 是指向这些参数的指针数组。*/
int main(int argc, char *argv[]) {
  int next_option;
  /* 包含所有有效短选项字母的字符串。*/
  const char *const short_options = "ho:v";
  /* 描述了长选项的 struct option 数组。*/
  const struct option long_options[] = {
      {"help", 0, NULL, 'h'},
      {"output", 1, NULL, 'o'},
      {"verbose", 0, NULL, 'v'},
      {NULL, 0, NULL, 0} /* 数组 要求这样一个元素。*/
  };
  /* 用于接受程序输出的文件名,如果为 NULL 则表示标准输出。*/
  const char *output_filename = NULL;
  /* 是否显示冗余信息?*/
  int verbose = 0;
  /* 记住程序的名字,可以用于输出的信息。名称保存在 argv[0]中。*/
  program_name = argv[0];
  do {
    next_option = getopt_long(argc, argv, short_options, long_options, NULL);
    switch (next_option) {
    case 'h': /* -h 或 --help */
      /* 用户要求查看使用帮助。输出到标准输出,退出程序并返回 0(正常结束)。*/
      print_usage(stdout, 0);
    case 'o': /* -o 或 --output */
      /* 此函数接受一个参数,表示输出文件名。*/
      output_filename = optarg;
      break;
    case 'v': /* -v 或 --verbose */
      verbose = 1;
      break;
    case '?': /* The user specified an invalid option. */ /* 向标准错误输出帮助信息,结束程序并返回
                                                         1(表示非正常退出)。*/
      print_usage(stderr, 1);
    case -1: /* 结束处理选项的过程。*/
      break;
    default: /* 别的什么:非预料中的。*/
      abort();
    }
  } while (next_option != -1);
  /* 选项处理完毕。OPTIND 指向第一个非选项参数。
   * 出于演示目的,如果指定了冗余输出选项,则输出这些参数。*/
  if (verbose) {
    int i;
    for (i = optind; i < argc; ++i)
      printf("Argument : %s\n", argv[i]);
  }

  char **var;
  for (var = environ; *var != NULL; ++var)
    printf("%s\n", *var);

  /* 主程序到这里结束。*/
  return 0;
}

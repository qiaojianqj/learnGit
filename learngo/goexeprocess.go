package main
import (
  "fmt"
  "os/exec"
  "os"
  "strings"
  "bytes"
)

func main() {
  env := os.Environ()
  //fmt.Println(env)
  procAtrr := &os.ProcAttr{
    Env: env,
    Files: [] *os.File{
      os.Stdin,
      os.Stdout,
      os.Stderr,
    },
  }
  //fmt.Println(procAtrr)
  pid, err := os.StartProcess("/bin/ls", []string{"ls", "-l"}, procAtrr)
  if err != nil{
    fmt.Printf("err %v in StartProcess", err)
    os.Exit(1)
  }
  fmt.Printf("The process id is %v\n", pid)

   cmd := exec.Command("tr", "a-z", "A-Z")
	cmd.Stdin = strings.NewReader("some input in lowercase to uppercase")
	var out bytes.Buffer
	cmd.Stdout = &out
	err = cmd.Run()
	if err != nil {
    fmt.Printf("err %v in exec cmd")
    os.Exit(1)
	}
	fmt.Printf("The cmd is %v\n", cmd)
	fmt.Printf("in all caps: %q\n", out.String())
}

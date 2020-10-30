package main
import (
	"fmt"
	"io/ioutil"
	"os"
	"flag"
	"path/filepath"
	"sync"
)

func direntries(dir string) []os.FileInfo{
	entries, err := ioutil.ReadDir(dir)
	if err != nil{
		return nil
	}
	return entries
}

func walkdir(dir string, wg *sync.WaitGroup, filesize chan<- int64){
	defer wg.Done()
	for _, entry := range direntries(dir){
		if entry.IsDir(){
			wg.Add(1)
			subdir := filepath.Join(dir, entry.Name())
			go walkdir(subdir, wg, filesize)
		}else{
			filesize <- entry.Size()
		}
	}
}

func printdiskusage(numfiles, numbytes int64){
	fmt.Printf("%d files, %.1f KB\n", numfiles, float64(numbytes)/1024)
}


func main(){
	flag.Parse()
	dirs := flag.Args()
	if len(dirs) == 0{
		dirs = []string{"."}
	}

	filesize := make(chan int64)
	var wg sync.WaitGroup
	for _, dir := range dirs{
		wg.Add(1)
		go walkdir(dir, &wg, filesize)
	}

	go func(){
		wg.Wait()
		close(filesize)
	}()

	var numfiles, numbytes int64
	for size := range filesize{
		numfiles++
		numbytes += size
	}
	printdiskusage(numfiles, numbytes)
}

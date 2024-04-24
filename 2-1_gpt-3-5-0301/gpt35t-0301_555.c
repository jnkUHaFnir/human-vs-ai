//find all open explorer windows
var explorerWindows = Process.GetProcesses().Where(p => p.ProcessName == "explorer");

//iterate through each explorer window
foreach(var window in explorerWindows)
{
   //get the folder path of the window
   string folderPath = window.MainWindowTitle.Replace("File Explorer - ", "");

   //check if the folder is located on the specific drive you want to eject
   if(folderPath.StartsWith("X:\\"))
   {
      //close the explorer window gracefully
      window.CloseMainWindow();
   }
}

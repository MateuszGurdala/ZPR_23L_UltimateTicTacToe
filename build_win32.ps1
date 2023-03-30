if (Test-Path -Path '.\build') {
}
else {
    Write-Output "Creating build folder"
    New-Item -Path ".\" -Name "build" -ItemType "directory"
}
Set-Location -Path '.\build'

Write-Output "Building CMAKE solution"
cmake ../
cmake --build .

Write-Output "Running app"
Set-Location -Path './Debug'
./UltimateTicTacToeServer

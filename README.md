# TF2 Present
An internal cheat base for Team Fortress 2, written in C++  
[Showcase video!](https://www.youtube.com/watch?v=gooAkpVujIU)
## How to use?
### Download
Run `git clone https://github.com/RileyKun/TF2-Present`  
or use the green download button above!
### Setup
Download Visual Studio 2022 with the desktop development package.  
### DirectX SDK Setup
1. Uninstall all Visual C++ 2010 Redistributables.
2. Download the 2010 DirectX SDK
3. Restart Visual Studio and verify that DirectX headers and libraries exist.
## Technical Features
Hooks `Present()` and `Reset()` virtual functions from the DirectX API.  
Does a signature scan for `IDirect3DDevice9` in `shaderapidx9.dll`.  
Has an easy to use system to draw text.  
Uses clang-cl/LLVM toolsets.
## FAQ
Q. Why?  
A. I grew tired of seeing everyone sludge around with Surface rendering
and wanted to make things more accessible for new developers and the like.  

Q. I keep getting an error related to d3dx9.h! What do I do?  
A. Read the setup instructions.

Q. If this is a cheat base, why is there no SDK files or basic features?  
A. This was more of a proof of concept and a decent reference for people to go by when they write their own hacks.  
  
Q. Do you plan on updating this base at all or adding anything to it?  
A. If I add anything, I will make a new repository. This is mainly just a proof of concept.
## Credits
- [D3X](https://github.com/angelfor3v3r/) - Assisting with hooks.  
- [Fedoraware](https://github.com/Fedoraware/Fedoraware) - Pattern scanner, interface manager & the signature for ID3DDevice9.  

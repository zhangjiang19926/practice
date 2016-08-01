" All system-wide defaults are set in $VIMRUNTIME/debian.vim (usually just
" /usr/share/vim/vimcurrent/debian.vim) and sourced by the call to :runtime
" you can find below.  If you wish to change any of those settings, you should
" do it in this file (/etc/vim/vimrc), since debian.vim will be overwritten
" everytime an upgrade of the vim packages is performed.  It is recommended to
" make changes after sourcing debian.vim since it alters the value of the
" 'compatible' option.

" This line should not be removed as it ensures that various options are
" properly set to work with the Vim-related packages available in Debian.
runtime! debian.vim

" Uncomment the next line to make Vim more Vi-compatible
" NOTE: debian.vim sets 'nocompatible'.  Setting 'compatible' changes numerous
" options, so any other options should be set AFTER setting 'compatible'.
"set compatible

" Vim5 and later versions support syntax highlighting. Uncommenting the next
" line enables syntax highlighting by default.
if has("syntax")
  syntax on
endif

" If using a dark background within the editing area and syntax highlighting
" turn on this option as well
"set background=dark

" Uncomment the following to have Vim jump to the last position when
" reopening a file
"if has("autocmd")
"  au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif
"endif

" Uncomment the following to have Vim load indentation rules and plugins
" according to the detected filetype.
"if has("autocmd")
"  filetype plugin indent on
"endif

" The following are commented out as they cause vim to behave a lot
" differently from regular Vi. They are highly recommended though.
"set showcmd		" Show (partial) command in status line.
"set ignorecase		" Do case insensitive matching
"set hidden             " Hide buffers when they are abandoned
"set mouse=a		" Enable mouse usage (all modes)
set showmatch		" Show matching brackets.
set smartcase		" Do smart case matching
set incsearch		" Incremental search
set incsearch		" Incremental search
set autowrite		" Automatically save before commands like :next and :make
set nu
"set relativenumber //设置相对行号

set tabstop=4
set softtabstop=4
set shiftwidth=4
set autoindent
set cindent 
set backspace=2
"set mapleader
let mapleader = ","
"Fast editing os the .vimrc 
map <silent> <leader>ee :e ~/.vimrc<cr>
"when .vimrc is edited , reload it  
autocmd! bufwritepost .vimrc source ~/.vimrc

"--状态行设置--
set laststatus=2 " 总显示最后一个窗口的状态行；设为1则窗口数多于一个的时候显示最后一个窗口的状态行；0不显示最后一个窗口的状态行
set ruler            " 标尺。

"--命令行设置--
set showcmd            " 命令行显示输入的命令
set showmode        " 命令行显示vim当前模式

"--find setting--
set incsearch        " 输入字符串就显示匹配点
set hlsearch  

"-----set the keys-----
inoremap jk <ESC>

"-----set the leader-----
let mapleader = ","
"autocmd FileType c,cpp map <buffer> <leader><space> :w<cr> :make<cr>
map <leader>cl :cclose<cr>
map <leader>ck :copen<cr>
nmap <leader>cn :cn<cr>
nmap <leader>cp :cp<cr>

"--设置jK为退出插入模式的按键
inoremap jk <ESC>
map wq :wq<cr>

"--快速查找光标下的单词-----
nmap <leader>lv :lv /<c-r>=expand("<cword>")<cr>/%<cr>:lw<cr>

"------quilkfix的设置--------
"autocmd FileType c,cpp
"nmap <leader>cn :cn<cr>
"nmap <leader>cp :cp<cr>
"nmap <leader>cw :cw 10<cr>
"nmap <leader>make :copen<cr> :make 

"-------MiniBufExplorer设置---------
map <leader>n :bn<cr>
map <leader>p :bp<cr>
map <leader>d :bd<cr> 

"-------方向键设置------------------
map <leader>h <c-w>h
map <leader>j <c-w>j
map <leader>k <c-w>k
map <leader>l <c-w>l

"-----taglist---------
let Tlist_Auto_Open=0
let Tlist_Ctags_Cmd='/usr/bin/ctags'
let Tlist_Use_Left_Window=1
let Tlist_Show_One_File=0
let Tlist_File_Fold_Auto_Close=0
let Tlist_Exit_OnlyWindow=1
let Tlist_Process_File_Always=1
let Tlist_Inc_Window=0
" Source a global configuration file if available
if filereadable("/etc/vim/vimrc.local")
  source /etc/vim/vimrc.local
endif


runtime! debian.vim
if has("syntax")
	syntax on
endif

if has("autocmd")
  au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif
endif

set autoindent          "duiqi
set smartindent         "zidongduiqi
set tabstop=4           "zhibiaofukuangdu
set shiftwidth=4	"shezhiruanzhibaiofudekuangdu 
set cindent             "C/C++yuyansuojin
set cinoptions={0,1s,t0,n-2,p2s,(03s,=.5s,>1s,=1s,:1s     "设置C/C++语言的具体缩进方式
set showmatch        " 设置匹配模式，显示匹配的括号
set linebreak        " 整词换行
set whichwrap=b,s,<,>,[,] " 光标从行首和行末时可以跳到另一行去
set history=50        " set command history to 50    "历史记录50条
set autowrite		" Automatically save before commands like :next and :make

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
"set nu
"--设置jK为退出插入模式的按键
inoremap jk <ESC>
map q :wq<cr>
map w :w<cr>
"--快速查找光标下的单词-----
nmap <leader>lv :lv /<c-r>=expand("<cword>")<cr>/%<cr>:lw<cr>
"------quilkfix的设置--------
autocmd FileType c,cpp
nmap <leader>cn :cn<cr>
nmap <leader>cp :cp<cr>
nmap <leader>cw :cw 10<cr>
nmap <leader>make :copen<cr> :make 

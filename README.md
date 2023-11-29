<hr />
<blockquote>
<p><em> <strong>PList Compiler</strong> is a property list compiler for XCode. It is developed as an <em>Open Source</em> project coming with a BSD License. The source code is currently hosted and developed on the <a href="http://sourceforge.net/projects/plistcompiler">SourceForge site.</a></em></p>
<p>This file documents version 0.2b1 of PList Compiler.</p>
</blockquote>
<hr />
<ul>
<li><a href="#M1">Introduction</a></li>
<li><a href="#M2">Usage</a>
<ul>
<li><a href="#M3">Default behavior</a></li>
</ul>
<ul>
<li><a href="#M4">Command line options</a></li>
</ul>
</li>
<li><a href="#M5">Howto</a>
<ul>
<li><a href="#M6">Using PList Compiler in an XCode project</a></li>
</ul>
<ul>
<li><a href="#M7">Using PList Compiler in Terminal</a></li>
</ul>
<ul>
<li><a href="#M8">Troubleshooting</a></li>
</ul>
</li>
<li><a href="#M9">Anatomy of 'plc' files</a>
<ul>
<li><a href="#M10">Comments</a></li>
</ul>
<ul>
<li><a href="#M11">The plc commands</a></li>
</ul>
<ul>
<ul>
<li><a href="#M12">The 'plist' command</a></li>
</ul>
</ul>
<ul>
<ul>
<li><a href="#M13">The 'dictionary' command</a></li>
</ul>
</ul>
<ul>
<ul>
<li><a href="#M14">The 'key' command</a></li>
</ul>
</ul>
<ul>
<ul>
<li><a href="#M15">The 'array' command</a></li>
</ul>
</ul>
<ul>
<ul>
<li><a href="#M16">The 'string' command</a></li>
</ul>
</ul>
<ul>
<ul>
<li><a href="#M17">The 'number' command</a></li>
</ul>
</ul>
<ul>
<ul>
<li><a href="#M18">The 'date' command</a></li>
</ul>
</ul>
<ul>
<ul>
<li><a href="#M19">The 'data' command</a></li>
</ul>
</ul>
<ul>
<ul>
<li><a href="#M20">The 'boolean' command</a></li>
</ul>
</ul>
<ul>
<li><a href="#M21">Localized files</a></li>
</ul>
<ul>
<ul>
<li><a href="#M22">The 'localize' command</a></li>
</ul>
</ul>
<ul>
<ul>
<li><a href="#M23">The 'comment' command</a></li>
</ul>
</ul>
</li>
<li><a href="#M24">Location of the output files</a></li>
<li><a href="#M25">Preprocessor directives</a>
<ul>
<li><a href="#M26">Defines</a></li>
</ul>
<ul>
<li><a href="#M27">Includes</a></li>
</ul>
<ul>
<li><a href="#M28">Conditional macros</a></li>
</ul>
<ul>
<ul>
<li><a href="#M29">Example 1</a></li>
</ul>
</ul>
<ul>
<ul>
<li><a href="#M30">Example 2</a></li>
</ul>
</ul>
<ul>
<ul>
<li><a href="#M31">Example 3</a></li>
</ul>
</ul>
<ul>
<ul>
<li><a href="#M32">Example 4</a></li>
</ul>
</ul>
<ul>
<li><a href="#M33">Errors and warnings</a></li>
</ul>
<ul>
<li><a href="#M34">Pragmas</a></li>
</ul>
<ul>
<ul>
<li><a href="#M35">The 'output_filename' pragma</a></li>
</ul>
</ul>
<ul>
<ul>
<li><a href="#M36">The 'in_package_directory' pragma</a></li>
</ul>
</ul>
<ul>
<ul>
<li><a href="#M37">The 'localize_directory' pragma</a></li>
</ul>
</ul>
<ul>
<ul>
<li><a href="#M38">The 'output_eol' pragma</a></li>
</ul>
</ul>
<ul>
<ul>
<li><a href="#M39">The 'output_encoding' pragma</a></li>
</ul>
</ul>
<ul>
<ul>
<li><a href="#M40">The 'plist_version' pragma</a></li>
</ul>
</ul>
</li>
<li><a href="#M41">Substitutable variables</a>
<ul>
<li><a href="#M42">Predefined variables</a></li>
</ul>
<ul>
<li><a href="#M43">XCode environment variables</a></li>
</ul>
<ul>
<li><a href="#M44">Unsupported variables</a></li>
</ul>
</li>
<li><a href="#M45">Unicode characters</a></li>
<li><a href="#M46">Download</a></li>
<li><a href="#M47">Known problems</a></li>
<li><a href="#M48">Version history</a></li>
<li><a href="#M49">License and disclaimer</a></li>
</ul>
<h2><a name="M1"></a>Introduction</h2>
<p><strong>PList Compiler</strong> is a property list compiler for XCode. It lets you build localized and non-localized plist files from plc and ploc source files. These are the property list files found in packages applications, bundles, frameworks, plugins, etc.</p>
<p>It is modelled on the CodeWarrior property list language: the idea of preparing source files and compiling them during the build process was introduced in CodeWarrior Pro 8. The language used in these source files lets you have the compiler build the property list files for you automatically, substituting the right values during the building process, instead of having to manage manually hard-coded XML files. CodeWarrior Pro 8 introduced a first draft of the plc language together with a dedicated compiler written by Josef W. Wankerl. Unfortunately XCode does not offer such a handy tool. Here comes <strong>PList Compiler</strong>!</p>
<p>It is a shell script, named <strong>plcompile</strong>, which is meant to be executed during a Shell Script Build Phase within an XCode project. It can also be run directly as a command line tool if you need to work only with plc files independently from the rest of your project.</p>
<p><strong>PList Compiler</strong> uses the same syntax as the original CodeWarrior compiler it supports most of its functionalities and adds many more to take advantage of all the XCode settings.</p>
<p><strong>PList Compiler</strong> is written in fact in <strong>Tcl</strong> (the <a href="http://wiki.tcl.tk/"> Tool Command Language</a>): the executable script is a <em>bash</em> script called <strong>plcompile</strong> which magically redirects the instructions to <em>tclsh</em> which is the Tcl shell. Tcl is installed by default on OSX since version 10.3 (aka Panther) so <em>tclsh</em> is normally present on every MacOSX system starting from this version, and there should be nothing special to do for this script to run there. For version 10.2 systems (aka Jaguar), you will have to install Tcl on your machine: you can, for instance, get Daniel Steffen's Tcl Batteries Included distribution <a href="http://www.maths.mq.edu.au/~steffen/tcltk/"> from there.</a></p>
<p><strong>PList Compiler</strong> comes with the same BSD license as Tcl itself. See the file <em>License_terms</em> included in this distribution or the <a href="http://www.opensource.org/licenses/bsd-license"> Open Source Initiative (OSI) site</a>.</p>
<h2><a name="M2"></a>Usage</h2>
<p>The syntax of the <strong>plcompile</strong> shell script is:</p>
<pre> plcompile options plcFile
 plcompile (-help | -encoding | -version)
</pre>
<p>The first form executes the compilation of the plc source file <em>plcFile</em>. Traditionnally these files have a <em>.plc</em> extension but this is not required at all. Most of the time you will not have to worry about the options. <strong>PList Compiler</strong> comes with reasonable defaults for the optional values, corresponding to a normal usage of these files in a project. The available options are explained below.</p>
<p>In the second form</p>
<pre>plcompile -help
plcompile -encoding
plcompile -version
</pre>
<p>the script prints some help in the console window: with <em>-help</em>, you get the usage string and a reminder of the defaults; with <em>-encoding</em>, you get a list of the available encodings; with <em>-version</em>, you get the current version number of the script. Note that one can use abbreviated flags like <em>-h</em> or <em>-v</em> for instance.</p>
<h3><a name="M3"></a>Default behavior</h3>
<p>By default, <strong>plcompile</strong> assumes that the input files are encoded in MacRoman and have Mac line endings (<em>cr</em>). The same type of line endings is used to write the output files but the encoding, this time, is the Unicode utf-8 form.</p>
<p>The default destination folder depends on how you execute the compiler:</p>
<ul>
<li>if you run the script from XCode as a <em>Shell Script phase</em> (this is the recommended way), the destination folder depends on the kind of product you are building: it is the <em>Contents</em> folder inside the application bundle when you are building a packaged application; in the case of a framework, it is the <em>Resources</em> subfolder of the frapmework ;</li>
<li>otherwise it is the same folder as the plc file being processed.</li>
</ul>
<p>These are default behaviors which can be modified with options on the command line or pragmas in the source files. See the <a href="#locout"> Location of the output files</a> section below.</p>
<h3><a name="M4"></a>Command line options</h3>
<p>The complete syntax to run the compiler is:</p>
<pre> plcompile [-input_encoding enc] [-output_encoding enc] [-input_eol eol]
 [-output_eol eol] [-dest folder] [-plist version] [-pkginfo] plcFile
</pre>
<p>The options have the following meaning:</p>
<ul>
<li>the <em>-input_encoding</em> option lets you specify in which encoding the source file should be read (by default <em>macRoman</em>);</li>
<li>the <em>-output_encoding</em> option lets you specify in which encoding the output files should be written (by default <em>utf-8</em>);</li>
<li>the <em>-input_eol</em> option lets you specify the type of line endings used in the source file (<em>cr</em> for Mac, <em>lf</em> for Unix and <em>crlf</em> for Windows);</li>
<li>the <em>-output_eol</em> option lets you specify the type of line endings used in the output files;</li>
<li>the <em>-dest</em> option lets you specify a destination folder relatively to which the output files will be produced. See the <a href="#locout"> Location of the output files</a> section below. Various pragmas can also be used to specify different subfolders inside the destination folder.</li>
<li>the <em>-plist</em> option lets you specify the version of the plist XML format (0.9 or 1.0). The default value is 1.0.</li>
<li>the <em>-pkginfo</em> option asks <em>PList Compiler</em> to also generate a <em>PkgInfo</em> file in the same folder as the <em>Info.plist</em> file. This can be useful because, when you turn off the plist stuff in Xcode, it stops generating itself the <em>PkgInfo</em> file.</li>
</ul>
<p><strong>Note:</strong> the <em>-pkginfo</em> option has been introduced in version 0.2 of <strong>PList Compiler</strong> by <a href="mailto:franz.detro@native-instruments.de"> Franz Detro</a> (thanks).</p>
<h2><a name="M5"></a>Howto</h2>
<h3><a name="M6"></a>Using PList Compiler in an XCode project</h3>
<p>The idea is to generate the various plist files and localized strings files during a <em>Shell Script Build Phase</em> within your XCode project. XCode lets you define <em>Shell Script Build Phases</em>: they are shell scripts which can be executed at any stage of the building process.</p>
<p>So, in order to use <strong>PList Compiler</strong> from XCode, you would normally create, in all the targets for which you want plist files to be generated, a build phase which could take place at the end of the build process. To create a <em>Shell Script Build Phase</em>, select the target you want in the <em>Groups and Files</em> panel of your main project window and select the <em>Shell Script Build Phase</em> command in the <em>New Build Phase</em> submenu of the <em>Project</em> menu. If you open the disclosure triangle located in front of the target's name, you will see your new shell phase (in XCode 2.1, it is called <em>Run Script</em>). Select it and click on the <em>Info</em> button in the toolbar (or select <em>Get Info</em> in the <em>File</em> menu).</p>
<p>XCode displays a window in which you can enter shell commands to execute. If your plc file is named MyApp.plc, you should just have to enter a command like</p>
<pre> plcompile /path/to/MyApp.plc
</pre>
<p>The only point is to make sure that the shell (Bash shell) can find the <strong>plcompile</strong> script. This depends on where you have put this script on your machine. If it is in one of the folders of your shell <tt>PATH</tt> variable, there should be no problem. Otherwise you can specify the complete path of the script, like for instance:</p>
<pre> /Users/bernardo/Devel/Tools/plcompile /path/to/MyApp.plc
</pre>
<p>or alternatively change the directory to this directory and execute the script there, like this:</p>
<pre> cd /Users/bernardo/Devel/Tools
 ./plcompile /path/to/MyApp.plc
</pre>
<p>supposing, in the previous example, that <strong>plcompile</strong> resides in <em>/Users/bernardo/Devel/Tools</em>.</p>
<h3><a name="M7"></a>Using PList Compiler in Terminal</h3>
<p>The <em>plcompile</em> script can be used directly from the command line (in a Terminal window). There is only one caveat with this approach: only the environment variables defined in the current shell window are available. This means that you must make sure, if ever your plc file makes use of environment variables defined by XCode, that they are available in the shell. You could have to define them manually. If your plc file does not need any of the values set by XCode, then you should normally be able to compile your plc files directly. You will probably want, in that case, to specify a destination folder using the <em>-dest</em> command line option.</p>
<p>For instance:</p>
<pre> /Developer/Tools/plcompile -dest ~/Devel/Tests myfile.plc
</pre>
<h3><a name="M8"></a>Troubleshooting</h3>
<p>In case the instructions above do not work as expected, here are a few indications to help solving the problem. Make sure that the plcompile script has been saved with Unix line endings (lf) rather than Mac line endings (cr). Some editors tend to change them in your back and the shell expects Unix line endings.</p>
<p>Make sure there is not an already existing <em>Info.plist</em> file in your source files added to your built product during the <em>Copy Bundle Resources</em> phase in order to avoid conflicts or files being overwritten.</p>
<p>Make sure, in the target settings, that no file has been declared in the <em>Info.plist File</em> setting (look in the <em>Packaging</em> section of the <em>General</em> settings).</p>
<p>Make sure of course that Tcl is installed on your machine. It is part of the Panther and Tiger installation.</p>
<p>If you are having trouble with the encodings, it is maybe because the text editor you used to create the <em>.plc</em> source files saved your files in utf-8. If your source file is utf-8 encoded, you will have to tell <strong>plcompile</strong> and specify the <em>-input_encoding</em> option, like this:</p>
<pre> ./plcompile -input_encoding utf-8 /path/to/MyApp.plc
</pre>
<p>Once again, the default is to read the source files in macRoman and to write the output files in utf-8.</p>
<p>Make sure you used the proper casing to specify the encodings: it is <em>macRoman</em> and not <em>MacRoman</em>, <em>utf-8</em> and not <em>UTF-8</em>. If you have a doubt, execute the following command which returns the list of all the available encodings:</p>
<pre> plcompile -encoding
</pre>
<p>If the script is not found by the shell, read the informations in the section above about executing shell phases in XCode and setting the access paths correctly.</p>
<h2><a name="M9"></a>Anatomy of 'plc' files</h2>
<p>The <em>.plc</em> source files are regular text files taken as input by <strong>PList Compiler</strong> in order to produce one or several output files. They contain three types of commands:</p>
<ul>
<li>preprocessor macros, simlar to those found in C or C++ source files;</li>
<li>specific commands understood and interpreted by the compiler;</li>
<li>comments ignored by the compiler.</li>
</ul>
<h3><a name="M10"></a>Comments</h3>
<p><strong>PList Compiler</strong> recognizes two kinds of comments: the C-like comments enclosed between /* and */ which can span multiple lines, and, on a single line, portions of text starting with a double slash (//) up to the end of the line. Be careful with the latter because, as of this version, the compiler is not clever enough to detect comment symbols included in a quoted string and which you would not like to be considered as a comment.</p>
<h3><a name="M11"></a>The plc commands</h3>
<p>Most of these commands correspond to an XML entity in the output <em>Info.plist</em> file. An <em>Info.plist</em> file is an XML document. The format of the plist files is specified by Apple in a DTD which can be found in <em>/System/Library/DTDs/PropertyList.dtd</em>. For a detailed description of property lists files, see for instance <a href="http://developer.apple.com/documentation/CoreFoundation/Conceptual/CFPropertyLists/index.html"> Introduction to Property Lists</a></p>
<p>All the commands must be kept on a separate line (but not necessarily at the beginning of the line).</p>
<h4><a name="M12"></a>The 'plist' command</h4>
<p>The first command found in a <em>.plc</em> file designed to generate a .plist file is always the <em>plist</em> command. Its argument is a block enclosed inside a pair of curly braces. A minimal property list file, describing a completely empty property list, would look like this:</p>
<pre> plist {}
</pre>
<p>The <em>plist</em> command corresponds to the &lt;plist&gt; XML tag.</p>
<h4><a name="M13"></a>The 'dictionary' command</h4>
<p>Directly inside the <em>plist</em> block, there is usually a <em>dictionary</em> command. This is not required by the DTD but all property lists in use are structured like this. Like with the <em>plist</em> command, the argument of a <em>dictionary</em> command is a block enclosed inside a pair of curly braces. So, a minimal valid plc source file would be:</p>
<pre> plist
 {
 dictionary {}
 }
</pre>
<p>The <em>dictionary</em> command corresponds to the &lt;dict&gt; XML tag.</p>
<p>The dictionary is made up of key/value pairs. The key names must be unique within a single dictionary. The value of a key can have any of the following types: <em>array, boolean, data, date, dictionary, number,</em> or <em>string</em>.</p>
<h4><a name="M14"></a>The 'key' command</h4>
<p>The key/value pairs are declared by instructions in the following format</p>
<pre> key "name_of_the_key" value "type_of_value" "the_value"
</pre>
<p>In this instruction, the <em>key</em> and <em>value</em> keywords correspond to the &lt;key&gt; and &lt;value&gt; XML tags respectively.</p>
<p>For instance, here is a valid key statement in a dictionary block:</p>
<pre> key "Victor Hugo" value string "Writer"
</pre>
<h4><a name="M15"></a>The 'array' command</h4>
<p>The <em>array</em> command is used to describe an ordered list of property list elements. These elements can be of any of the abovementioned types <em>(array, boolean, data, date, dictionary, number, string).</em></p>
<p>The original specification of the plc syntax in CodeWarrior stipulated that the argument of an <em>array</em> command is a block enclosed inside a pair of square brackets. With <strong>PList Compiler</strong>, you can also use curly braces instead of square brackets.</p>
<p>Here is an example of an array containing a dictionary and a boolean value:</p>
<pre> array
 {
 boolean true
 dictionary {
 key "Victor Hugo" value string "Writer"
 key "Ludwig van Beethoven" value string "Composer"
 }
 }
</pre>
<h4><a name="M16"></a>The 'string' command</h4>
<p>The <em>string</em> command lets you specify a string value. Strings are enclosed in double quotes in order to distinguish them from a substitutable variable (see below), but this is not required. If there is no risk of ambiguity, you can suppress the quotes. Still it is good programming practice to write them.</p>
<p>The value of a string can be made up of several pieces, mixing quoted strings or variables. For instance:</p>
<pre> string "copyright (c) " __YEAR__ ", all rights reserved"
</pre>
<p>where <tt>__YEAR__</tt> is one of the predefined variables set by the compiler. This string will be expanded to something like <em>copyright (c) 2005, all rights reserved</em>. The <em>string</em> command corresponds to the &lt;string&gt; XML tag.</p>
<p><strong>Caveat:</strong> in order to ensure a better compatibility with the CodeWarrior property list compiler which accepted both <em>single</em> and <em>double</em> quotes to delimit strings, PList Compiler does its best to support the same convention. For instance:</p>
<pre>string 'RSRC'
</pre>
<p>will produce <em>&lt;string&gt;RSRC&lt;/string&gt;</em> as it did with the CodeWarrior property list compiler. As a consequence, this makes it a little more difficult to obtain values enclosed in quotes in the output file. For instance, if you really want to get a string value like 'RSRC' or "RSRC" (including the quotes), you will have to code it like this:</p>
<pre>string "'RSRC'"
string "\"" RSRC "\""
</pre>
<p>Be also aware that, in the case where you concatenate several strings or mix strings and variables, single quotes will confuse the compiler and the odds are very high that you won't obtain what you expect, so your best bet is to always use double quotes (and no quotes at all for substitutable variables).</p>
<h4><a name="M17"></a>The 'number' command</h4>
<p>The <em>number</em> command lets you specify numeric values. There is no XML tag named <em>number</em> in a plist file, but rather two entities named &lt;real&gt; and &lt;integer&gt; corresponding respectively to integer or floating point values. The <em>number</em> command corresponds to both of them: the compiler automatically decides to which type the value belongs. For instance, the following declarations will result in an &lt;integer&gt; tag:</p>
<pre> number 0
 number 1
 number -1
</pre>
<p>while the following ones will yield &lt;real&gt; tags:</p>
<pre> number 0.0
 number 3.14
 number -2.718
 number .1
 number -.1
 number 6.09e23
</pre>
<h4><a name="M18"></a>The 'date' command</h4>
<p>The <em>date</em> command lets you specify a date value. The plist format specification (in <em>/System/Library/DTDs/PropertyList.dtd</em>) suggests that</p>
<blockquote>
<p><em> the contents of a date value should conform to a subset of ISO 8601: in particular, YYYY '-' MM '-' DD 'T' HH ':' MM ':' SS 'Z'. Smaller units may be omitted with a loss of precision. </em></p>
</blockquote>
<p>For instance:</p>
<pre> date "2005-09-15 18:06:03"
 date "2005-09-15T18:06:03Z"
 date __DATE__
</pre>
<p>where <tt>__DATE__</tt> is one of the predefined variables set by the compiler. The <em>date</em> command corresponds to the &lt;date&gt; XML tag.</p>
<h4><a name="M19"></a>The 'data' command</h4>
<p>The <em>data</em> command is used to store raw binary data. The value of a data type is expressed in the plc file in hexadecimal format, possibly with space characters, like for instance:</p>
<pre> data "64656667"
 data "64 65 66 67"
 data "64 65" "66 67"
</pre>
<p>In the output file, the same data is represented in Base64 encoding as recommended in the DTD specifying the plist format (see <em>/System/Library/DTDs/PropertyList.dtd</em>). All the values above are equivalent and are represented like this in Base64 encoding:</p>
<p>&lt;data&gt;ZGVmZw==&lt;/data&gt;</p>
<p>The <em>data</em> command corresponds to the &lt;data&gt; XML tag.</p>
<p><strong>Note:</strong> the CodeWarrior plist compiler also defined a <em>data file</em> command followed by the name of a file containing raw data. This is not implemented by <strong>PList Compiler</strong> as of version 0.1.</p>
<h4><a name="M20"></a>The 'boolean' command</h4>
<p>The <em>boolean</em> command lets you specify a boolean value using any of the usual keywords: true/false, yes/no, and 1/0. Casing does not matter, so TRUE, true or True are all acceptable values. The value can be enclosed in double quotes but this is not required.</p>
<p>For example:</p>
<pre> key "kGcc_Precompile_Prefix_Header" value boolean 1
 key "kGcc_Symbols_Private_Extern" value boolean 0
 key "kGenerate_Profiling_Code" value boolean Yes
 key "kUse_Dynamic_No_Pic" value boolean "false"
 key "kZero_Link" value string __ZERO_LINK__
</pre>
<p>The last example is correct because XCode defines a ZERO_LINK variable whose value can be either "YES" or "NO" (see below).</p>
<p>The <em>boolean</em> command corresponds to the &lt;boolean&gt; XML tag.</p>
<h3><a name="M21"></a>Localized files</h3>
<p>The localized files contain lists of keyed strings localized for a particular language.</p>
<h4><a name="M22"></a>The 'localize' command</h4>
<p>The <em>localize</em> command is used to create and generate localized strings files. It is a top level command like the <em>plist</em> command. There are two possible syntaxes to invoke this command:</p>
<pre> localize "language"
 localize "language" as "localized_file_name"
</pre>
<p>The first form is used to localize string values present in the main property list dictionary of the <em>plist</em> command. The resulting file is named by default <em>InfoPlist.strings</em> instead of <em>Info.plist</em>, and is located inside the localized folder corresponding to the specified language instead of the <em>Contents</em> folder. For instance:</p>
<pre> /Contents/Resources/Spanish.lproj/InfoPlist.strings
</pre>
<p>The second form of the <em>localize</em> command specifies the name of the generated file rather than relying on the default name. This allows to create several separate strings files. These files will also be created in the folder corresponding to the specified language.</p>
<p>The argument of the <em>localize</em> command is a block enclosed in a pair of curly braces. Only two commands can be used inside a localize block: <em>key</em> and <em>comment</em>. The <em>key</em> command defines key/value statements of type <em>string</em>. For instance:</p>
<pre> localize "French"
 {
 key "CFBundleGetInfoString" value string "MyApp, (c) 2005, tous droits r&eacute;serv&eacute;s"
 key "CFBundleHelpBookName" value string "Aide PList Compiler"
 }
 localize "Spanish" as "Dialogs.strings"
 {
 key "Number of Recent Items:" value string "N&uacute;mero de &iacute;tems recientes:"
 key "General Preference Pane" value string "Panel de preferencias General"
 }
</pre>
<p>The first instruction generates <em>MyApp.app/Contents/Resources/French.lproj/InfoPlist.strings</em> and the scond one <em>MyApp.app/Contents/Resources/Spanish.lproj/Dialogs.strings</em></p>
<p>It is current practice to put the <em>localize</em> blocks in separate files and use a <em>.ploc</em> extension in their name to distinguish them from the <em>.plc</em> files. The <em>.ploc</em> files are usually invoked from the main <em>.plc</em> file with an <tt>#include</tt> preprocessor command. For instance:</p>
<pre> #include "DialogStrings_Spanish.ploc"
</pre>
<h4><a name="M23"></a>The 'comment' command</h4>
<p>The <em>comment</em> command lets you insert comments inside the localized strings files. There can be as many commands of this type in a <em>localize</em> block as necessary. The value of the command is a string or concatenation of strings and expandable variables: once concatenated and substituted, it is inserted inside a C-like comment of the form <tt>/* */</tt> in the output file. For instance, the following instruction might be found in some <em>.ploc</em> file:</p>
<pre> localize "English" as "Dialogs.strings"
 {
 comment "Generated from " __FILE__ " at " __TIME__
 }
</pre>
<p>The <tt>__FILE__</tt> and the <tt>__TIME__</tt> symbols used in this example are predefined variables: <tt>__FILE__</tt> always contains the name of the file being currently processed by the compiler and <tt>__TIME__</tt> the time at the moment the compiler processes the file. If the instruction above was stored in a file named <em>dialogStrings_EN.ploc</em>, the comment generated in the resulting <em>Dialogs.strings</em> file (in the /Contents/Resources/English.lproj folder inside the bundle) would look like this:</p>
<pre> /* Generated from dialogStrings_EN.ploc at 23:54:25 */
</pre>
<p><strong>Caveat:</strong> the <em>comment</em> command can't be used in a <em>plist</em> block.</p>
<p><a name="locout"></a></p>
<h2><a name="M24"></a>Location of the output files</h2>
<p>By default, the <em>plist</em> command causes <strong>PList Compiler</strong> to create a file named <em>Info.plist</em> inside the destination directory. In the case of a packaged application, the default destination directory is the <em>Contents</em> folder inside the bundle. More generally, the path of this destination folder is built by <strong>PList Compiler</strong> using the values of the <tt>BUILT_PRODUCTS_DIR</tt> and <tt>INFOPLIST_PATH</tt> XCode variables.</p>
<p>For instance, with XCode 2.1, if your target is in the <em>Release</em> configuration and your application is MyApp, the destination folder would be (unless you have non standard settings):</p>
<pre> $SRCROOT/build/Release/MyApp.app/Contents
</pre>
<p>where <tt>SRCROOT</tt> is, as usual the folder containing your project file.</p>
<p>By default, the <em>localize</em> command causes <strong>PList Compiler</strong> to create localized files. The default location for these files depends on the language used for the localization. In the case of a packaged application, the default destination is inside one of the <em>/Contents/Resources/&lt;language&gt;.lproj</em> subfolders of the bundle. For instance <em>/Contents/Resources/English.lproj</em> or <em>/Contents/Resources/French.lproj</em>.</p>
<p>There are two ways of modifying the destination folders:</p>
<ul>
<li>from the command line, using the <em>-dest</em> option</li>
<li>using one of the <em>in_package_directory</em> or <em>localize_directory</em> pragmas (see below)</li>
</ul>
<p>The output file name (usually Info.plist) can be modified using the <em>output_filename</em> pragma. See the <em>Pragmas</em> section below.</p>
<h2><a name="M25"></a>Preprocessor directives</h2>
<p>This is the other type of instruction found in plc source files. They are called preprocessor directives by analogy with the C/C++ language. They are also sometimes refered to as preprocessor macros. The preprocessor term is not quite accurate here because there are not two phases like with the ordinary C compilers (a preprocessing phase and a compiling phase): <strong>PList Compiler</strong> parses the file once, line by line.</p>
<p>The following macros are supported by <strong>PList Compiler</strong>:</p>
<table border="0" cellpadding="1">
<tbody>
<tr>
<td>#define</td>
<td>#message</td>
<td>#if</td>
<td>#elif</td>
</tr>
<tr>
<td>#include</td>
<td>#warning</td>
<td>#ifdef</td>
<td>#else</td>
</tr>
<tr>
<td>#pragma</td>
<td>#error</td>
<td>#ifndef</td>
<td>#endif</td>
</tr>
</tbody>
</table>
<p>Preprocessor directives all occur on their own line. They are characterized by the fact that the first non-whitespace character on the line is a #. There may be whitespace characters between the # mark and the name of the directive too.</p>
<h3><a name="M26"></a>Defines</h3>
<p>The <em>#define</em> directive lets you define a macro in the property list compiler. The format is:</p>
<pre> #define macro_name macro_text
</pre>
<p>The compiler adds the macro <em>macro_name</em> to its macro table: if there is already a macro with this name, it emits an error. When <em>macro_name</em> appears in a plc source file as the value of a string type not enclosed between double quotes, it is automatically replaced by <em>macro_text</em>.</p>
<p>For instance, if a macro <em>kVersionNumber</em> is defined like this:</p>
<pre> #define kVersionNumber "1.2.3"
</pre>
<p>then, when the compiler encounters the following instruction:</p>
<pre> key "CFBundleShortVersionString" value string "kVersionNumber: " kVersionNumber
</pre>
<p>it expands it to <em>kVersionNumber: 1.2.3</em></p>
<p>The <em>#undef</em> directive tells the compiler to remove an already existing macro from its macro table. The syntax is:</p>
<pre> #undef macro_name
</pre>
<p>If <em>macro_name</em> does not exist, the directive is just ignored.</p>
<p><strong>Note:</strong> the same remarks as with the <em>string</em> keyword apply here concerning the use of single quotes as string delimiters. They are supported in the case of simple string values but not in concatenations. Use double quotes to be safe.</p>
<h3><a name="M27"></a>Includes</h3>
<p>The <em>#include</em> directive tells the plist compiler to find another plc source file and start processing it. The syntax of this directive has two forms:</p>
<p>#include "filename"</p>
<p>#include &lt;filename&gt;</p>
<p>The <em>filename</em> value designates a file to include: it can be either an absolute or a relative path. A relative path is resolved by searching relatively to various folders: in the first form, <strong>PList Compiler</strong> will first try to resolve the path relatively to the folder containing the parent source file (i-e, the file which invokes the <em>#include</em> directive). If this fails, it will try all the paths defined in XCode's <tt>HEADER_SEARCH_PATHS</tt> variable. In the second form, where the filename is enclosed in angle brackets, only the paths defined in the <tt>HEADER_SEARCH_PATHS</tt> variable are searched.</p>
<p>The following are all valid examples (the double quotes are necessary only if the filename contains space characters):</p>
<pre> #include /Users/bernardo/Devel/MyApp/Rsrc/OtherFile.plc
 #include OtherFile.plc
 #include "LocFiles/My Strings_EN.ploc"
 #include "../Rsrc/My Strings_EN.ploc"
</pre>
<p><strong>Note:</strong> the second form of the <em>#include</em> directive is a code contribution by <a href="mailto:franz.detro@native-instruments.de"> Franz Detro</a> (thanks) and has been introduced in version 0.2 of <strong>PList Compiler</strong>.</p>
<h3><a name="M28"></a>Conditional macros</h3>
<p><strong>PList Compiler</strong> supports the following six conditional directives: <em><em>#if</em>, <em>#ifdef</em>, <em>#ifndef</em>, <em>#elif</em>, <em>#else</em>, <em>#endif</em></em> which let you build conditional blocks of instructions depending on the value of a test expression or on the existence or non-existence of a particular variable.</p>
<p>The <em>#ifdef</em> directive tests for the definition of a compiler macro, while the <em>#ifndef</em> directive tests for the non-definition of this macro. Their behavior is the opposite of one another. In the case of <em>#ifdef</em> for instance, if the macro has been previously defined, the property list code immediately following the <em>#ifdef</em> directive is processed until an <em>#else</em> or <em>#endif</em> directive is encountered, but on the contrary, if the macro has not been defined, the property list code immediately following the <em>#ifdef</em> directive is not processed. In that case, if there is an <em>#else</em> directive, instead the code following this <em>#else</em> is processed until the matching <em>#endif</em> directive is found.</p>
<p>Similarly, if the expression in an <em>#if</em> directive evaluates to 1, the instructions immediately following the <em>#if</em> directive are executed until an <em>#else</em>, <em>#elif</em>, or <em>#endif</em> directive is encountered. If the expression evaluates to 0, the property list code immediately following the <em>#if</em> directive is not processed.</p>
<p>Each <em>#if</em>, <em>#ifdef</em>, <em>#ifndef</em> directive must be matched by an <em>#endif</em> directive.</p>
<p>The <em>#elif</em> directive allows for multiple successive <em>#if</em> tests during the preprocessing stage. An <em>#elif</em> test is evaluated only if all the preceding tests have failed.</p>
<p>Here are a few examples of conditional constructs.</p>
<h4><a name="M29"></a>Example 1</h4>
<p>Note in this example that for testing equality you must use a double equal sign (==). A single equal sign would provoke an error.</p>
<pre> #define kVersionFive 5
 #define kVersionSeven 7
 #define kCurrentVersion kVersionFive
 #if kCurrentVersion == kVersionSeven
 #warning "Current version is " kVersionSeven
 #else
 #warning "Current version is not " kVersionSeven
 #endif
</pre>
<h4><a name="M30"></a>Example 2</h4>
<p>This example demonstrates nested conditional blocks.</p>
<pre> #define kVersionFive 5
 #define kVersionSix 6
 #define kVersionSeven 7
 #define kCurrentVersion kVersionSeven
 #if kCurrentVersion == kVersionSeven
 #warning "Current version is " kVersionSeven
 #else
 #if kCurrentVersion &lt;= kVersionFive
 #warning "Current version &lt;= " kVersionFive
 #else
 #warning "Current version &gt; " kVersionFive
 #endif
 #warning "Done comparison with kVersionFive"
 #endif
</pre>
<h4><a name="M31"></a>Example 3</h4>
<p>Here is an example using <em>#ifdef</em> and <em>#ifndef</em> directives:</p>
<pre> #undef kUndefinedMacro
 #ifdef kUndefinedMacro
 # define kWillNeverBeDefinedMacro
 #endif
 #ifndef kWillNeverBeDefinedMacro
 # define kHasNotBeenDefined "No, it has not been defined"
 #else
 # define kHasBeenDefined "Yes, it has been defined"
 #endif
</pre>
<h4><a name="M32"></a>Example 4</h4>
<p>Here is an example using the <em>#elif</em> directive:</p>
<pre> #define kVersionFive 5
 #define kVersionSix 6
 #define kVersionSeven 7
 #define kVersionEight 8
 #define kCurrentVersion kVersionSix
 #if kCurrentVersion &lt;= kVersionFive
 #warning "Current version is &lt;= " kVersionFive
 #elif kCurrentVersion &lt;= kVersionEight
 #if kCurrentVersion == kVersionSix
 #warning "Current version is " kVersionSix
 #elif kCurrentVersion == kVersionSeven
 #if kCurrentVersion &lt; 0
 #warning "Current version is negative!"
 #elif kCurrentVersion &gt; 10
 #warning "Current version is &gt; 10"
 #else
 #warning "Current version is between 1 and 10"
 #endif
 #else
 #warning "Current version is " kVersionEight
 #endif
 #else
 #warning "Current version is &gt; " kVersionEight
 #endif
</pre>
<h3><a name="M33"></a>Errors and warnings</h3>
<p>The <em>#error</em> directive raises an error and stops the execution of the compiler. This is generally used in combination with <em>#if</em> directives to test for situations that should never occur.</p>
<p>The <em>#warning</em> directive emits a message in the console. The <em>#message</em> directive is just a synonym for <em>#warning</em>.</p>
<p>Here are a few examples:</p>
<pre> #warning "Fix the version number before shipping"
 #message "PList Compiler is great!!!"
 #if __PLIST__ &lt; 1.0
 #error "The property list version is too old"
 #endif
</pre>
<h3><a name="M34"></a>Pragmas</h3>
<p>Pragmas are directives used to modify the internal state of the compiler. They let you modify some internal settings during the execution of the plc file. They are most useful to modify locally a global setting: the new value set by a pragma holds until another pragma modifies it again. A pragma is declared with the <em>#pragma</em> directive. The syntax is:</p>
<pre> #pragma pragma_name [pragma_value]
</pre>
<p>The supported pragmas are explained below. The <em>pragma_name</em> argument can be one of the following keywords: <em>output_filename, in_package_directory, localize_directory, output_eol, output_encoding, plist_version.</em></p>
<p>Any other pragma encountered will be simply ignored by <strong>PList Compiler</strong>. In particular the <em>once</em>, <em>notonce</em>, and <em>mark</em> pragmas, defined by the CodeWarrior compiler, are not supported, as of version 0.1.</p>
<p><strong>Caution:</strong> a pragma cannot be used inside a <em>plist</em> or a <em>localize</em> block. It must be invoked outside these environments. This is because the internal settings they affect can't be modified once a file has been opened for output. The compiler will emit an error if such a situation occurs.</p>
<h4><a name="M35"></a>The 'output_filename' pragma</h4>
<p>The <em>output_filename</em> pragma lets you override the default name of the current output file. Its value is a string which is the new name. For instance:</p>
<pre> #pragma output_filename "OtherName.plist"
</pre>
<p>The new name given with this pragma is used only once and then forgotten, so that the compiler immediately returns to the default naming convention. Note that this does not affect the filename defined in a 'localize as' command. More precisely, if the compiler reads the following inxtructions:</p>
<pre> #pragma output_filename "OtherName.txt"
 localize "Spanish" as "Error.strings"
 {
 }
</pre>
<p>the pragma will have no effect and the output file will still be named <em>Error.strings</em>. On the other hand, the pragma will remain in effect until it can be applied.</p>
<h4><a name="M36"></a>The 'in_package_directory' pragma</h4>
<p>The <em>in_package_directory</em> pragma lets you specify where to place the property list file inside the destination folder. It is a string which specifies a directory <em>relative</em> to the destination folder. For instance, if you write:</p>
<pre> #pragma in_package_directory "Infos"
</pre>
<p>the <em>Info.plist</em> file will be written in an <em>Infos</em> subfolder of the destination folder rather than in the destination folder directly. If the subfolder does not exist, it is created. By default, this will be <em>MyApp.app/Contents/Infos</em> (unless another destination folder has been otherwise specified).</p>
<p>Another valid value for this pragma could be:</p>
<pre> #pragma in_package_directory "../Infos/Properties"
</pre>
<p>which would write the output file in <em>MyApp.app/Infos/Properties</em>, i-e with the <em>Infos</em> directory at the same level as the <em>Contents</em> directory.</p>
<h4><a name="M37"></a>The 'localize_directory' pragma</h4>
<p>While the previous pragma affected the final location of the <em>Info.plist</em> files (produced by the <em>plist</em> command), the <em>localize_directory</em> pragma lets you specify where to place the localized strings files produced by the <em>localize</em> command. It is a string which specifies a directory <em>relative</em> to the destination folder. By default, it is the <em>Resources</em> folder inside the destination folder which itself is, by default, the <em>Contents</em> subfolder of the bundle. For instance:</p>
<pre> #pragma localize_directory "Local/Strings/"
</pre>
<p>will cause the localized strings files to be written in some <em>MyApp.app/Contents/Local/Strings/&lt;language&gt;.lproj</em> folder (depending on the chosen language) instead of <em>MyApp.app/Contents/Resources/&lt;language&gt;.lproj</em>.</p>
<h4><a name="M38"></a>The 'output_eol' pragma</h4>
<p>The <em>output_eol</em> pragma lets you specify another type of line endings for the output files. The possible values are <em>cr</em> for Mac, <em>lf</em> for Unix and <em>crlf</em> for Windows. This pragma is useful to override a setting made with the <em>-output_eol</em> option on the command line of the <strong>plcompile</strong> shell script.</p>
<pre> #pragma output_eol lf
</pre>
<h4><a name="M39"></a>The 'output_encoding' pragma</h4>
<p>The <em>output_eol</em> pragma lets you specify another encoding for the output files. The possible values are listed when you execute the command:</p>
<pre> plcompile -help
</pre>
<p>You would normally be interested only in the utf-8 and utf-16 encoding forms which are the only encodings recognized for property list files. <strong>PList Compiler</strong> is able though to handle all the other encodings.</p>
<p>This pragma is useful to override a setting made with the <em>-output_encoding</em> option on the command line of the <strong>plcompile</strong> shell script. For instance:</p>
<pre> #pragma output_encoding utf-16
</pre>
<p>Note that there is no equivalent pragma concerning the input encoding because it does not make sense: the input file would have already been read when the pragma is encountered.</p>
<h4><a name="M40"></a>The 'plist_version' pragma</h4>
<p>The <em>plist_version</em> pragma lets you specify another version of the property list format. The possible values currently are 0.9 and 1.0. This is the value written in the <em>version</em> attribute of the &lt;plist&gt; tag in the <em>.plist</em> files. For instance:</p>
<pre> #pragma plist_version 0_9
</pre>
<p>yields &lt;plist version="0_9"&gt;</p>
<p>This is the same value stored in the <tt>__PLIST__</tt> predefined variable (see below).</p>
<h2><a name="M41"></a>Substitutable variables</h2>
<p>Substitutable variables are variables whose value is inserted when the script is run. These variables can be defined with a <em>#define</em> preprocessor macro or in the shell environment. There are also some useful predefined variables set by the plc compiler itself.</p>
<p>To invoke a variable defined in the shell environment, you must surround it with double underscores. This concerns in particular all the variables available in an XCode project, but not only: ordinary shell environment variables, such as <tt>USER</tt>, <tt>DISPLAY</tt>, <tt>SHELL</tt>, etc. are also accessible as <tt>__USER__</tt>, <tt>__DISPLAY__</tt>, <tt>__SHELL__</tt>, respectively.</p>
<p>Variables defined with a <em>#define</em> macro can be invoked directly (without the double underscores). For instance, if you define</p>
<pre> #define kBundleShortVersion "1.2.3"
</pre>
<p>you can then have a key in the <em>plist</em> dictionary declared like this</p>
<pre> key "CFBundleVersion" value string kBundleShortVersion
</pre>
<p>For variables which can be set at different levels, the order of precedence is the following: an option set by a <em>#define</em> directive or modified by a <em>#pragma</em> directive in the plc source file overrides any option set on the command line which, in turn, overrides an option set by a shell environment variable.</p>
<h3><a name="M42"></a>Predefined variables</h3>
<p>A few predefined variables are set each time the <strong>plcompile</strong> script is run.</p>
<p>The five following variables existed in the CodeWarrior property list compiler. They are still available with <strong>PList Compiler</strong> in order to ensure some compatibility with already existing plc files (and because they are very useful!):</p>
<p><strong>__FILE__</strong></p>
<dl>
<dt>This variable always contains the name of the file currently processed. If another file is included with an <em>#include</em> preprocessor macro, the value of the variable is changed accordingly so that it always designates the file being processed.</dt>
</dl>
<p><strong>__OUTPUT_CREATOR__</strong></p>
<dl>
<dt>This variable contains the creator type of the built product. It corresponds to the MACOS_CREATOR XCode variable.</dt>
</dl>
<p><strong>__OUTPUT_TYPE__</strong></p>
<dl>
<dt>This variable contains the file type of the built product. It corresponds to the MACOS_TYPE XCode variable.</dt>
</dl>
<p><strong>__OUTPUT_FILENAME__</strong></p>
<dl>
<dt>This variable contains the name of the built product. It is equivalent to the concatenation of the PRODUCT_NAME and WRAPPER_EXTENSION XCode variables.</dt>
</dl>
<p><strong>__DATE__</strong></p>
<dl>
<dt>This is the complete date at the moment where the script is executed. It is returned in the format specified by the ISO 8601 standard: YY-MM-DDTHH:MM:SSZ. For instance <em>"2005-10-04T17:12:23Z"</em>.</dt>
</dl>
<p><strong>Caveat:</strong> one must be aware that the values of the <tt>OUTPUT_CREATOR</tt> and <tt>OUTPUT_TYPE</tt> predefined variables are taken from the XCode variables called <tt>MACOS_CREATOR</tt> and <tt>MACOS_TYPE</tt>, but that, in certain circumstances, these variables are not displayed in the <em>Target Settings</em> panels in <em>XCode</em>. The variables do exist but simply are not displayed by default. As a consequence, their value in that case is empty. This is a problem with <em>XCode</em>, not with <em>PList Compiler</em>. The remedy, should this situation occur, is to add these variables manually in the <em>Target Settings</em> using the <em>Plus</em> button and to give them the necessary values corresponding to your project.</p>
<p>Furthermore <strong>PList Compiler</strong> introduces other useful predefined variables:</p>
<p><strong>__YEAR__</strong></p>
<dl>
<dt>The current year (four digits)</dt>
</dl>
<p><strong>__MONTH__</strong></p>
<dl>
<dt>The current month number (01 - 12)</dt>
</dl>
<p><strong>__MONTHNAME__</strong></p>
<dl>
<dt>The full month name (January, etc.)</dt>
</dl>
<p><strong>__DAY__</strong></p>
<dl>
<dt>The current day of month (01 - 31)</dt>
</dl>
<p><strong>__DAYNAME__</strong></p>
<dl>
<dt>The full day name (Monday, etc.)</dt>
</dl>
<p><strong>__SHORTDATE__</strong></p>
<dl>
<dt>The current date as YYYY-MM-DD.</dt>
</dl>
<p><strong>__TIME__</strong></p>
<dl>
<dt>The current time as HH:MM::SS.</dt>
</dl>
<p><strong>__HOURS__</strong></p>
<dl>
<dt>The hours part of the TIME string.</dt>
</dl>
<p><strong>__MINUTES__</strong></p>
<dl>
<dt>The minutes part of the TIME string.</dt>
</dl>
<p><strong>__SECONDS__</strong></p>
<dl>
<dt>The seconds part of the TIME string.</dt>
</dl>
<p>For instance:</p>
<pre> __DATE__ = 2005-10-04T15:54:36Z
 __SHORTDATE__ = 2005-10-04
 __YEAR__ = 2005
 __MONTH__ = 10
 __MONTHNAME__ = October
 __DAY__ = 04
 __DAYNAME__ = Tuesday
 __TIME__ = 15:54:36
 __HOURS__ = 15
 __MINUTES__ = 54
 __SECONDS__ = 36
</pre>
<h3><a name="M43"></a>XCode environment variables</h3>
<p>All the environment variables set by an XCode project are accessible with <strong>PList Compiler</strong>. See the XCode documentation for a complete list. The syntax is the same as for the predefined variables: the name of the environment variable must be surrounded by double underscores. For instance, if you want to invoke the value of the INFOPLIST_PATH variable defined in an XCode project, you would write it as <tt>__INFOPLIST_PATH__</tt> in the plc file. For instance</p>
<pre> key "InfoPlistPath" value string __INFOPLIST_PATH__
</pre>
<p>Some of these variables are set by XCode itself (they are generally meant to be read-only variables) while the others can be set in the info window or a particular target. The name of a variable corresponding to a particular setting is always indicated by XCode between parentheses in the help text displayed when you select this setting in a Target Info window.</p>
<h3><a name="M44"></a>Unsupported variables</h3>
<p>A few predefined variables available in the CodeWarrior property list compiler are not supported by <strong>PList Compiler</strong>. This is mainly because they are specific to the CodeWarrior IDE and have no meaning with XCode. Here is the list of these variables:</p>
<pre> __APPLEMACHLINKER__, __MACH__, __MERGELINKER__,
 __MWMACHLINKER__, __MWPEFLINKER__
</pre>
<p>The <tt>__LINE__</tt> variable is not supported either, as well as the <tt>__IDE_TARGET__()</tt> and <tt>__STRING__()</tt> pseudo-macros.</p>
<h2><a name="M45"></a>Unicode characters</h2>
<p>By default, <strong>PList Compiler</strong> assumes that the input file is UTF-8 encoded and it generates its output files in the same encoding. So there is no problem for supporting any Unicode character in your plc source files: you just have to use a text editor which handles the UTF-8 encoding form. If you prefer editing your plc source files in macRoman, all you have to do is to specify this to the <em>plcompile</em> script using the <em>-input_encoding</em> option.</p>
<p>Alternatively, if you just need occasionnally to use Unicode characters, you can also embed them in strings using the <tt>\u</tt> escape sequence: each Unicode character can be designated using the sequence <tt>\u</tt> followed by the code-point of the character in hexadecimal. For instance, the Unicode code-points for the lowercase letters of the greek alphabet start at 03B1:</p>
<table border="1" cellpadding="1">
<tbody>
<tr>
<td><em>Code-point</em></td>
<td><em>Letter</em></td>
</tr>
<tr>
<td>03B1</td>
<td>GREEK SMALL LETTER ALPHA</td>
</tr>
<tr>
<td>03B2</td>
<td>GREEK SMALL LETTER BETA</td>
</tr>
<tr>
<td>03B3</td>
<td>GREEK SMALL LETTER GAMMA</td>
</tr>
<tr>
<td>03B4</td>
<td>GREEK SMALL LETTER DELTA</td>
</tr>
<tr>
<td>03B5</td>
<td>GREEK SMALL LETTER EPSILON</td>
</tr>
<tr>
<td>03B6</td>
<td>GREEK SMALL LETTER ZETA</td>
</tr>
<tr>
<td>03B7</td>
<td>GREEK SMALL LETTER ETA</td>
</tr>
<tr>
<td>03B8</td>
<td>GREEK SMALL LETTER THETA</td>
</tr>
<tr>
<td>03B9</td>
<td>GREEK SMALL LETTER IOTA</td>
</tr>
</tbody>
</table>
<p>A string defined like this</p>
<pre> key "UniString1" value string "\u03B1 \u03B2 \u03B3 \u03B4 \u03B5 \u03B6 \u03B7 \u03B8 \u03B9"
</pre>
<p>will produce:</p>
<p>&alpha; &beta; &gamma; &delta; &epsilon; &zeta; &eta; &theta; &iota;</p>
<p><strong>Note:</strong> the sequence to designate Unicode characters is <tt>\u</tt> with a <em>lowercase u</em>. This is a difference with the CodeWarrior property list compiler which used \U.</p>
<h2><a name="M46"></a>Download</h2>
<p><strong>PList Compiler</strong> is an Open Source Project. Its source code is freely available and can be found on the SourceForge site at the following address:</p>
<p><a href="http://sourceforge.net/projects/plistcompiler">http://sourceforge.net/projects/plistcompiler</a></p>
<p>PList Compiler releases are available at</p>
<p><a href="http://sourceforge.net/project/showfiles.php?group_id=149940">http://sourceforge.net/project/showfiles.php?group_id=149940</a></p>
<p>or on my web page at</p>
<p><a href="http://webperso.easyconnect.fr/bdesgraupes/plistcompiler.html">http://webperso.easyconnect.fr/bdesgraupes/plistcompiler.html</a></p>
<p>The code is under CVS control. You can retrieve the latest stage of development using any CVS client. See instructions at:</p>
<p><a href="http://sourceforge.net/cvs/?group_id=149940">http://sourceforge.net/cvs/?group_id=149940</a></p>
<p>You can browse the cvs repository online at</p>
<p><a href="http://cvs.sourceforge.net/cgi-bin/viewcvs.cgi/plistcompiler">http://cvs.sourceforge.net/cgi-bin/viewcvs.cgi/plistcompiler</a></p>
<p>You can also download a nightly tarball from</p>
<p><a href="http://cvs.sourceforge.net/cvstarballs/plistcompiler-cvsroot.tar.bz2">http://cvs.sourceforge.net/cvstarballs/plistcompiler-cvsroot.tar.bz2</a></p>
<h2><a name="M47"></a>Known problems</h2>
<p>Please e-mail any problem or bug you encounter:</p>
<p><a href="mailto:bdesgraupes@users.sourceforge.net">bdesgraupes@users.sourceforge.net</a></p>
<p>Visit my Web page for updates and other recent builds:</p>
<p><a href="http://webperso.easyconnect.fr/bdesgraupes/plistcompiler.html">http://webperso.easyconnect.fr/bdesgraupes/plistcompiler.html</a></p>
<p>Visit the PList Compiler project area on the SourceForge site:</p>
<p><a href="http://sourceforge.net/projects/plistcompiler">http://sourceforge.net/projects/plistcompiler</a></p>
<p>There is also a mailing list, <strong>plistcompiler-users</strong>, for discussing any topics related to the usage of PList Compiler and its future development. New versions will be announced on this list too. You can subscribe or unsubscribe from the following address:</p>
<p><a href="http://lists.sourceforge.net/mailman/listinfo/plistcompiler-users">http://lists.sourceforge.net/mailman/listinfo/plistcompiler-users</a> To post to this list, send mail to <a href="mailto:plistcompiler-users@lists.sourceforge.net">plistcompiler-users@lists.sourceforge.net</a></p>
<h2><a name="M48"></a>Version history</h2>
<p>For a detailed list of the changes, see the file <em>Changes_PLC</em> in the CVS repository.</p>
<ul>
<li>2005-10-10 - 0.1b1 - First public beta release. Basic implementation.</li>
<li>2005-10-12 - 0.1b2 - Fixed bug when #including pathname with whitespace.</li>
<li>2005-10-13 - 0.1b3 - Improved use of single quotes. Minor fixes. Unicode characters.</li>
<li>2005-10-14 - 0.1rc1 - First release candidate.</li>
<li>2005-11-03 - 0.1 - First final release. Added -version option.</li>
<li>2005-11-23 - 0.2 - Support for Headers Search Paths in #include directives. Command line option to generate the PkgInfo file.</li>
</ul>
<h2><a name="M49"></a>License and disclaimer</h2>
<p><strong>PList Compiler</strong> is distributed under the same BSD License as the Tcl language itself: see the file <em>License_terms</em> in the distribution or the <a href="http://www.opensource.org/licenses/bsd-license"> Open Source Initiative site.</a></p>
<hr />
<p>Last updated 2005-11-23 10:03:09</p>

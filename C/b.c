#include <stdio.h>
#include <string.h>
char* quoted(char* a, char* b)
{
	int i=0,j=0;
	b[j++] = '\"';
	for(;i<strlen(a);) {
		if(a[i]=='\n') {
			b[j++] = '\\';
			b[j++] = 'n';
			i++;
		}
		else if(a[i]=='\t') {
			b[j++] = '\\';
			b[j++] = 't';
			i++;
		}
		else if(a[i]=='\\') {
			b[j++] = '\\';
			b[j++] = '\\';
			i++;
		}
		else if(a[i]=='\"') {
			b[j++] = '\\';
			b[j++] = '\"';
			i++;
		}
		else {
			b[j++] = a[i++];
		}
	}
	b[j++] = '\"';
	return b;
}
char* replace(char* a, char* b, char* c)
{
	int i=0,j=0,k=0;
	for(;i<strlen(a);) {
		if(a[i]==64) {
			for(;j<strlen(b);)
				c[k++] = b[j++];
			i++;
		}
		else {
			c[k++] = a[i++];
		}
	}
	return c;
}
int main()
{
	char a[] = "#include <stdio.h>\n#include <string.h>\nchar* quoted(char* a, char* b)\n{\n\tint i=0,j=0;\n\tb[j++] = '\\\"';\n\tfor(;i<strlen(a);) {\n\t\tif(a[i]=='\\n') {\n\t\t\tb[j++] = '\\\\';\n\t\t\tb[j++] = 'n';\n\t\t\ti++;\n\t\t}\n\t\telse if(a[i]=='\\t') {\n\t\t\tb[j++] = '\\\\';\n\t\t\tb[j++] = 't';\n\t\t\ti++;\n\t\t}\n\t\telse if(a[i]=='\\\\') {\n\t\t\tb[j++] = '\\\\';\n\t\t\tb[j++] = '\\\\';\n\t\t\ti++;\n\t\t}\n\t\telse if(a[i]=='\\\"') {\n\t\t\tb[j++] = '\\\\';\n\t\t\tb[j++] = '\\\"';\n\t\t\ti++;\n\t\t}\n\t\telse {\n\t\t\tb[j++] = a[i++];\n\t\t}\n\t}\n\tb[j++] = '\\\"';\n\treturn b;\n}\nchar* replace(char* a, char* b, char* c)\n{\n\tint i=0,j=0,k=0;\n\tfor(;i<strlen(a);) {\n\t\tif(a[i]==64) {\n\t\t\tfor(;j<strlen(b);)\n\t\t\t\tc[k++] = b[j++];\n\t\t\ti++;\n\t\t}\n\t\telse {\n\t\t\tc[k++] = a[i++];\n\t\t}\n\t}\n\treturn c;\n}\nint main()\n{\n\tchar a[] = @;\n\tchar b[986];\n\tchar c[1791];\n\tb[986] = '\\0';\n\tc[1791] = '\\0';\n\tprintf(\"%s\",replace(a,quoted(a,b),c));\n}";
	char b[986];
	char c[1791];
	b[986] = '\0';
	c[1791] = '\0';
	printf("%s",replace(a,quoted(a,b),c));
}
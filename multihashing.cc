#include <node.h>
#include <node_buffer.h>
#include <v8.h>
#include <stdint.h>

extern "C" {
  //   #include "bcrypt.h"
  //   #include "keccak.h"
  //   #include "quark.h"
  //   #include "scryptjane.h"
  //   #include "scryptn.h"
  //   #include "skein.h"
  //   #include "x11.h"
  //   #include "groestl.h"
  //   #include "blake.h"
  //   #include "fugue.h"
  //   #include "qubit.h"
  //   #include "hefty1.h"
  //   #include "shavite3.h"
  //   #include "cryptonight.h"
  //   #include "x13.h"
  //   #include "nist5.h"
  //   #include "sha1.h"
  //   #include "x15.h"
	 // #include "fresh.h"
    #include "lbry.h"
}



using namespace node;
using namespace v8;

Handle<Value> except(const char* msg) {
    return ThrowException(Exception::Error(String::New(msg)));
}


Handle<Value> lbry(const Arguments& args) {
    HandleScope scope;

    if (args.Length() < 1)
        return except("You must provide one argument.");

    Local<Object> target = args[0]->ToObject();

    if(!Buffer::HasInstance(target))
        return except("Argument should be a buffer object.");

    char * input = Buffer::Data(target);
    char output[32];

    unsigned int dSize = Buffer::Length(target);

    lbry_hash(input, output);

    Buffer* buff = Buffer::New(output, 32);
    return scope.Close(buff->handle_);
}





void init(Handle<Object> exports) {
    // exports->Set(String::NewSymbol("quark"), FunctionTemplate::New(quark)->GetFunction());
    // exports->Set(String::NewSymbol("x11"), FunctionTemplate::New(x11)->GetFunction());
    // exports->Set(String::NewSymbol("scrypt"), FunctionTemplate::New(scrypt)->GetFunction());
    // exports->Set(String::NewSymbol("scryptn"), FunctionTemplate::New(scryptn)->GetFunction());
    // exports->Set(String::NewSymbol("scryptjane"), FunctionTemplate::New(scryptjane)->GetFunction());
    // exports->Set(String::NewSymbol("keccak"), FunctionTemplate::New(keccak)->GetFunction());
    // exports->Set(String::NewSymbol("bcrypt"), FunctionTemplate::New(bcrypt)->GetFunction());
    // exports->Set(String::NewSymbol("skein"), FunctionTemplate::New(skein)->GetFunction());
    // exports->Set(String::NewSymbol("groestl"), FunctionTemplate::New(groestl)->GetFunction());
    // exports->Set(String::NewSymbol("groestlmyriad"), FunctionTemplate::New(groestlmyriad)->GetFunction());
    // exports->Set(String::NewSymbol("blake"), FunctionTemplate::New(blake)->GetFunction());
      exports->Set(String::NewSymbol("lbry"), FunctionTemplate::New(lbry)->GetFunction());
    // exports->Set(String::NewSymbol("fugue"), FunctionTemplate::New(fugue)->GetFunction());
    // exports->Set(String::NewSymbol("qubit"), FunctionTemplate::New(qubit)->GetFunction());
    // exports->Set(String::NewSymbol("hefty1"), FunctionTemplate::New(hefty1)->GetFunction());
    // exports->Set(String::NewSymbol("shavite3"), FunctionTemplate::New(shavite3)->GetFunction());
    // exports->Set(String::NewSymbol("cryptonight"), FunctionTemplate::New(cryptonight)->GetFunction());
    // exports->Set(String::NewSymbol("x13"), FunctionTemplate::New(x13)->GetFunction());
    // exports->Set(String::NewSymbol("boolberry"), FunctionTemplate::New(boolberry)->GetFunction());
    // exports->Set(String::NewSymbol("nist5"), FunctionTemplate::New(nist5)->GetFunction());
    // exports->Set(String::NewSymbol("sha1"), FunctionTemplate::New(sha1)->GetFunction());
    // exports->Set(String::NewSymbol("x15"), FunctionTemplate::New(x15)->GetFunction());
    //  exports->Set(String::NewSymbol("fresh"), FunctionTemplate::New(fresh)->GetFunction());
}

NODE_MODULE(multihashing, init)

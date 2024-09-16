import { dlopen, FFIType, suffix } from "bun:ffi";

const { void: cvoid, i32 } = FFIType;
const path_hello = `dylib/hello.${suffix}`;
const path_hello_me = `dylib/sum.${suffix}`;

console.log("SUFFIX:", suffix);

const lib_hello = dlopen(path_hello, {
  hello: {
    returns: cvoid,
  },
});

const lib_sum = dlopen(path_hello_me, {
  get_sum: {
    args: [i32, i32],
    returns: i32,
  },
});

lib_hello.symbols.hello();
console.log(lib_sum.symbols.get_sum(3, 6));

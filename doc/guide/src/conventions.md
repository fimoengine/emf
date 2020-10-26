# Conventions

The interfaces specified by EMF follow some conventions, that the reader should keep in mind.

## Versions

EMF makes use of Semantic versioning, albeit in a more restricted form.

### Specification

> **<sup>Syntax</sup>**\
>\<valid semver> ::=\
> &nbsp;&nbsp; &nbsp;&nbsp; \<version core>\
> &nbsp;&nbsp; | \<version core> "-" \<pre-release>\
> &nbsp;&nbsp; | \<version core> "+" \<build>\
> &nbsp;&nbsp; | \<version core> "-" \<pre-release> "+" \<build>
>
>\<version core> ::=\
> &nbsp;&nbsp; &nbsp;&nbsp; \<major> "." \<minor> "." \<patch>
>
>\<major> ::=\
> &nbsp;&nbsp; &nbsp;&nbsp; \<numeric identifier>
>
>\<minor> ::=\
> &nbsp;&nbsp; &nbsp;&nbsp; \<numeric identifier>
>
>\<patch> ::=\
> &nbsp;&nbsp; &nbsp;&nbsp; \<numeric identifier>
>
>\<pre-release> ::=\
> &nbsp;&nbsp; &nbsp;&nbsp; \<pre-release identifier> "." \<digits>
>
>\<build> ::=\
> &nbsp;&nbsp; &nbsp;&nbsp; \<digits>
>
>\<dot-separated build identifiers> ::=\
> &nbsp;&nbsp; &nbsp;&nbsp; \<build identifier>\
> &nbsp;&nbsp; | \<build identifier> "." \<dot-separated build identifiers>
>
>\<numeric identifier> ::=\
> &nbsp;&nbsp; &nbsp;&nbsp; "0"\
> &nbsp;&nbsp; | \<positive digit>\
> &nbsp;&nbsp; | \<positive digit> \<digits>
>
>\<digits> ::=\
> &nbsp;&nbsp; &nbsp;&nbsp; \<digit>\
> &nbsp;&nbsp; | \<digit> \<digits>
>
>\<digit> ::=\
> &nbsp;&nbsp; &nbsp;&nbsp; "0"\
> &nbsp;&nbsp; | \<positive digit>
>
>\<pre-release identifier> ::=\
> &nbsp;&nbsp; &nbsp;&nbsp; "pre-alpha" | "alpha" | "beta" | "rc"
>
>\<positive digit> ::=\
> &nbsp;&nbsp; &nbsp;&nbsp; "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"

Concretely, a version must have the form: \
> `Major.Minor.Patch(-(pre-alpha|alpha|beta|rc).Pre-Release-Build)?(+Build)?`

A version is unstable if it is a `pre-alpha` or `alpha` version. 
A `beta` or `rc` version is api-stable and a `gold` version is stable.

### Order and Equality

The set of all versions is totally ordered. 

We define three different order relations <=<sub>1</sub>, <=<sub>2</sub>, <=<sub>3</sub>, which we will call weakly, normally or strongly ordered. 
We will use <= as a replacement for <=<sub>2</sub>.

#### Equality

Two versions `v` and `w` are equal if:

- Weak Equality: `v` ==<sub>1</sub> `w` <=> `v` <=<sub>1</sub> `w` && `w` <=<sub>1</sub> `v`
- Normal Equality: `v` == `w` <=> `v` <= `w` && `w` <= `v`
- Strong Equality: `v` ==<sub>2</sub> `w` <=> `v` <=<sub>2</sub> `w` && `w` <=<sub>2</sub> `v`

#### Weak Order

For two versions `v` and `w`, the order <=<sub>1</sub> is defined as follows:

> 1. Sort by Majors.
> 2. Sort by Minors.
> 3. Sort by Patch.

#### Normal Order

For two versions `v` and `w`, the order <= is defined as follows:

> 1. Sort `v` and `w`, so that `v` <=<sub>2</sub> `w`.
> 2. Sort by pre-release, with `"pre-alpha" < "alpha" < "beta" < "rc" < "gold"`.
> 3. Sort by pre-release build.

#### Strong Order

For two versions `v` and `w`, the order <=<sub>3</sub> is defined as follows:

> 1. Sort `v` and `w`, so that `v` <=<sub>2</sub> `w`.
> 2. Sort by build.

#### Examples

- `0.1.0` <=<sub>1</sub> `1.0.0`
- `1.2.3` <=<sub>1</sub> `1.3.0`
- `5.17.35` <=<sub>1</sub> `5.17.36`
- `2.1.1-alpha.10` ==<sub>1</sub> `2.1.1-beta.5`
- `1.0.0-rc.1` <= `1.0.0`
- `2.4.0-alpha.9` <= `2.4.0-alpha.10`
- `2.3.9+15686` == `2.3.9+15687`
- `2.3.9+15686` <=<sub>3</sub> `2.3.9+15687`

### Compatibility

Two versions are compatible if the first can be replaced with the second, without any break in functionality.\
The compatibility of two differing versions `v` and `w`, with `v` <=<sub>1</sub> `w`, is specified in the tables below.

#### Case `v` ==<sub>1</sub> `w` && `v` <= `w`:

| Version          | `w` is pre-alpha | `w` is alpha | `w` is beta | `w` is rc | `w` is gold |
| ---------------- | ---------------- | ------------ | ----------- | --------- | ----------- |
| `v` is Pre-Alpha | No               | No           | No          | No        | No          |
| `v` is Alpha     | No               | No           | No          | No        | No          |
| `v` is Beta      | No               | No           | Yes         | Yes       | Yes         |
| `v` is Rc        | No               | No           | No          | Yes       | Yes         |
| `v` is Gold      | No               | No           | No          | No        | Yes         |

#### Else:

For the versions to be compatible, bot tables must show a `Yes`.

| Version         | `v.Major` != `w.Major` | `v.Minor` != `w.Minor` | `v.Patch` != `w.Patch` |
| --------------- | ---------------------- | ---------------------- | ---------------------- |
| `v=0.x.y-z.i+j` | No                     | No                     | Yes                    |
| `v=x.y.z-i.j+k` | No                     | Yes                    | Yes                    |

<br>

| Version           | `w` is unstable | `w` is api-stable | `w` is stable |
| ----------------- | --------------- | ----------------- | ------------- |
| `v` is unstable   | No              | No                | No            |
| `v` is api-stable | Yes             | Yes               | Yes           |
| `v` is stable     | Yes             | Yes               | Yes           |

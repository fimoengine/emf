import click
import json
import time


def get_version_string(major, minor, patch):
    return "{}.{}.{}".format(major, minor, patch)


def get_version_string_long(major, minor, patch, pre_release_type, pre_release_build):
    if pre_release_type == 0:
        return get_version_string(major, minor, patch)
    else:
        pre_release_type_strings = ['stable', 'unstable', 'beta']
        pre_release_type_string = pre_release_type_strings[pre_release_type]

        return get_version_string(major, minor, patch) + '-{}.{}'.format(pre_release_type_string, pre_release_build)


def get_version_string_full(major, minor, patch, pre_release_type, pre_release_build, build):
    return get_version_string_long(major, minor, patch, pre_release_type, pre_release_build) + '+{}'.format(build)


def get_build_number(build, version_dict):
    if build == -1:
        return int(time.time())
    elif build == -2:
        return version_dict['build']
    else:
        return build


@click.group()
def cli():
    pass


@click.command()
@click.argument('version', type=click.File('r'))
@click.argument('output', type=click.File('w'))
@click.option('--source', default=6,
              help='0: Major, 1: Minor, 2: Patch, 3: Pre-release type, 4: Pre-release build, 5: Build, 6: Version, '
                   '7: Long version, 8: Full version')
@click.option('--build', default=-1, help='The build version (-1 for UNIX timestamp, -2 for embedded build).')
def extract(version, output, source, build):
    version_dict = json.load(version)
    major = version_dict['major']
    minor = version_dict['minor']
    patch = version_dict['patch']
    pre_release_type = version_dict['pre_release_type']
    pre_release_build = version_dict['pre_release_build']
    build = get_build_number(build, version_dict)

    version_string = get_version_string(major, minor, patch)
    version_string_long = get_version_string_long(
        major, minor, patch, pre_release_type, pre_release_build)
    version_string_full = get_version_string_full(
        major, minor, patch, pre_release_type, pre_release_build, build)

    if source == 0:
        output.write('{}'.format(major))
    elif source == 1:
        output.write('{}'.format(major))
    elif source == 2:
        output.write('{}'.format(patch))
    elif source == 3:
        output.write('{}'.format(pre_release_type))
    elif source == 4:
        output.write('{}'.format(pre_release_build))
    elif source == 5:
        output.write('{}'.format(build))
    elif source == 6:
        output.write('{}'.format(version_string))
    elif source == 7:
        output.write('{}'.format(version_string_long))
    elif source == 8:
        output.write('{}'.format(version_string_full))


@click.command()
@click.argument('version', type=click.File('r'))
@click.option('--build', default=-1, help='The build version (-1 for UNIX timestamp, -2 for embedded build).')
def print(version, build):
    version_dict = json.load(version)
    major = version_dict['major']
    minor = version_dict['minor']
    patch = version_dict['patch']
    pre_release_type = version_dict['pre_release_type']
    pre_release_build = version_dict['pre_release_build']
    build = get_build_number(build, version_dict)

    version_string = get_version_string(major, minor, patch)
    version_string_long = get_version_string_long(
        major, minor, patch, pre_release_type, pre_release_build)
    version_string_full = get_version_string_full(
        major, minor, patch, pre_release_type, pre_release_build, build)

    click.echo("Version: {}".format(version_string))
    click.echo("Version long: {}".format(version_string_long))
    click.echo("Version full: {}".format(version_string_full))


@click.command()
@click.argument('input', type=click.File('r'))
@click.argument('output', type=click.File('w'))
@click.argument('version', type=click.File('r'))
@click.option('--build', default=-1, help='The build version (-1 for UNIX timestamp, -2 for embedded build).')
@click.option('--major_key', default='MAJOR', help='The keyword to replace with the major number.')
@click.option('--minor_key', default='MINOR', help='The keyword to replace with the minor number.')
@click.option('--patch_key', default='PATCH', help='The keyword to replace with the patch number.')
@click.option('--pre_release_type_key', default='RELEASE_TYPE',
              help='The keyword to replace with the pre-release type number.')
@click.option('--pre_release_build_key', default='RELEASE_NUMBER',
              help='The keyword to replace with the pre-release build number.')
@click.option('--build_key', default='BUILD', help='The keyword to replace with the build number.')
@click.option('--version_key', default='STRING_SHORT', help='The keyword to replace with the version string.')
@click.option('--version_long_key', default='STRING_LONG', help='The keyword to replace with the long version string.')
@click.option('--version_full_key', default='STRING_FULL', help='The keyword to replace with the full version string.')
@click.option('--prefix', default='', help='The prefix of all keywords to replace.')
@click.option('--suffix', default='', help='The suffix of all keywords to replace.')
@click.option('--delimiter', default='!', help='The delimiter of all keywords to replace.')
def replace(input, output, version, build, major_key, minor_key, patch_key, pre_release_type_key, pre_release_build_key,
            build_key, version_key, version_long_key, version_full_key, prefix, suffix, delimiter):
    version_dict = json.load(version)
    major = version_dict['major']
    minor = version_dict['minor']
    patch = version_dict['patch']
    pre_release_type = version_dict['pre_release_type']
    pre_release_build = version_dict['pre_release_build']
    build = get_build_number(build, version_dict)

    version_string = get_version_string(major, minor, patch)
    version_string_long = get_version_string_long(
        major, minor, patch, pre_release_type, pre_release_build)
    version_string_full = get_version_string_full(
        major, minor, patch, pre_release_type, pre_release_build, build)

    major_key = '{0}{1}{2}{3}{0}'.format(delimiter, prefix, major_key, suffix)
    minor_key = '{0}{1}{2}{3}{0}'.format(delimiter, prefix, minor_key, suffix)
    patch_key = '{0}{1}{2}{3}{0}'.format(delimiter, prefix, patch_key, suffix)
    pre_release_type_key = '{0}{1}{2}{3}{0}'.format(
        delimiter, prefix, pre_release_type_key, suffix)
    pre_release_build_key = '{0}{1}{2}{3}{0}'.format(
        delimiter, prefix, pre_release_build_key, suffix)
    build_key = '{0}{1}{2}{3}{0}'.format(delimiter, prefix, build_key, suffix)
    version_key = '{0}{1}{2}{3}{0}'.format(
        delimiter, prefix, version_key, suffix)
    version_long_key = '{0}{1}{2}{3}{0}'.format(
        delimiter, prefix, version_long_key, suffix)
    version_full_key = '{0}{1}{2}{3}{0}'.format(
        delimiter, prefix, version_full_key, suffix)

    input_string = input.read()
    input_string = input_string.replace(major_key, '{}'.format(major))
    input_string = input_string.replace(minor_key, '{}'.format(minor))
    input_string = input_string.replace(patch_key, '{}'.format(patch))
    input_string = input_string.replace(
        pre_release_type_key, '{}'.format(pre_release_type))
    input_string = input_string.replace(
        pre_release_build_key, '{}'.format(pre_release_build))
    input_string = input_string.replace(build_key, '{}'.format(build))
    input_string = input_string.replace(
        version_key, '{}'.format(version_string))
    input_string = input_string.replace(
        version_long_key, '{}'.format(version_string_long))
    input_string = input_string.replace(
        version_full_key, '{}'.format(version_string_full))

    output.write(input_string)


cli.add_command(extract)
cli.add_command(print)
cli.add_command(replace)

if __name__ == '__main__':
    cli()

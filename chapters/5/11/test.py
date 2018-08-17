#!/usr/bin/env python3
import unittest
import subprocess
from subprocess import PIPE


class KnownIndents(unittest.TestCase):
    known_indents = (
        ('hello world!           how are you?',
         b'hello world!\t       how are you?'),  # shell operates in bytes
        ('        f f f f f f f',
         b'\tf f f f\tf f f')
    )

    def test_knowns(self):
        '''entab should indent text correctly'''
        for (orig, result) in self.known_indents:
            cmd = 'echo -n "{}" | ./a.out'.format(orig)
            output = subprocess.run(cmd, check=True, stdout=PIPE,
                                    shell=True).stdout
            self.assertEqual(result, output)


if __name__ == '__main__':
    unittest.main()

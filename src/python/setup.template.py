from setuptools import setup, find_packages

setup(name='pfunction', \
      version='VERSION_ID (git sha COMMIT_ID)', \
      description='Function passing library', \
      author='Brian Puchala',\
      author_email='bpuchala@umich.edu',\
      url='REPO_URL', \
      packages=find_packages(),
      python_requires='=2.7',
      license='LGPL2.1+',
      classifiers=[
        'Development Status :: 4 - Beta',
        'License :: OSI Approved :: GNU Lesser General Public License v2 or later (LGPLv2+)',
        'Programming Language :: Python',
        'Programming Language :: Python :: 2.7',
        'Topic :: Scientific/Engineering'
      ],
      data_files = [('', ['LICENSE'])])
